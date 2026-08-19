class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;

        function<vector<string>(int)> dfs = [&](int start) {
            if (start == s.size()) {
                return vector<string>{""};
            }

            if (memo.count(start)) {
                return memo[start];
            }

            vector<string> result;

            for (int end = start + 1; end <= s.size(); end++) {
                string word = s.substr(start, end - start);

                if (dict.count(word)) {
                    vector<string> rest = dfs(end);

                    for (string sentence : rest) {
                        if (sentence.empty()) {
                            result.push_back(word);
                        } else {
                            result.push_back(word + " " + sentence);
                        }
                    }
                }
            }

            return memo[start] = result;
        };

        return dfs(0);
    }
};