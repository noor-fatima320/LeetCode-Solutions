class Solution {
public:

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string p : parent[word]) {
            path.push_back(p);

            dfs(p, beginWord, path);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> dict(
            wordList.begin(),
            wordList.end()
        );

        // endWord must exist
        if (!dict.count(endWord)) {
            return {};
        }

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, int> dist;
        dist[beginWord] = 0;

        bool found = false;

        while (!q.empty() && !found) {

            int size = q.size();

            // Words discovered at this BFS level
            unordered_set<string> used;

            for (int i = 0; i < size; i++) {

                string current = q.front();
                q.pop();

                int currentDist = dist[current];

                for (int j = 0; j < current.size(); j++) {

                    string next = current;

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (c == current[j])
                            continue;

                        next[j] = c;

                        // Not in dictionary
                        if (!dict.count(next))
                            continue;

                        // First time reaching this word
                        if (!dist.count(next)) {

                            dist[next] = currentDist + 1;

                            q.push(next);

                            parent[next].push_back(current);

                            used.insert(next);

                            if (next == endWord) {
                                found = true;
                            }
                        }

                        // Another shortest way to reach same word
                        else if (dist[next] == currentDist + 1) {

                            parent[next].push_back(current);
                        }
                    }
                }
            }

            // Remove only after completing the whole level.
            // This allows multiple parents at the same shortest level.
            for (string word : used) {
                dict.erase(word);
            }
        }

        // No path exists
        if (!dist.count(endWord)) {
            return {};
        }

        // Build paths backwards from endWord
        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};