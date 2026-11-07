
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> available;

        priority_queue<pair<long long, pair<int, int>>,
            vector<pair<long long, pair<int, int>>>,
            greater<pair<long long, pair<int, int>>>> busy;

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);
        long long time = 0;

        for (int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            while (!busy.empty() && busy.top().first <= time) {
                auto curr = busy.top();
                busy.pop();

                available.push({
                    curr.second.first,
                    curr.second.second
                });
            }

            if (available.empty()) {
                time = busy.top().first;

                while (!busy.empty() && busy.top().first <= time) {
                    auto curr = busy.top();
                    busy.pop();

                    available.push({
                        curr.second.first,
                        curr.second.second
                    });
                }
            }

            auto server = available.top();
            available.pop();

            int weight = server.first;
            int index = server.second;

            ans[i] = index;

            busy.push({
                time + tasks[i],
                {weight, index}
            });
        }

        return ans;
    }
};
