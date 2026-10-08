class Twitter {
private:
    struct Tweet {
        int id;
        int time;
    };

    vector<vector<Tweet>> userTweets;
    vector<unordered_set<int>> followings;
    int timer;

public:
    Twitter() {
        timer = 0;
        userTweets.resize(501);
        followings.resize(501);
    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({tweetId, timer++});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // User's own tweets
        if (!userTweets[userId].empty()) {
            int index = userTweets[userId].size() - 1;
            pq.push({
                -userTweets[userId][index].time,
                userId,
                index
            });
        }

        // Followed users' tweets
        for (int followee : followings[userId]) {
            if (!userTweets[followee].empty()) {
                int index = userTweets[followee].size() - 1;

                pq.push({
                    -userTweets[followee][index].time,
                    followee,
                    index
                });
            }
        }

        while (!pq.empty() && result.size() < 10) {
            auto [negativeTime, user, index] = pq.top();
            pq.pop();

            result.push_back(userTweets[user][index].id);

            // Move to the previous tweet of this user
            if (index > 0) {
                int nextIndex = index - 1;

                pq.push({
                    -userTweets[user][nextIndex].time,
                    user,
                    nextIndex
                });
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};