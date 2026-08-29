class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq;
        vector<string> ans;

        for (int i = 0; i + 10 <= s.length(); i++) {
            string sub = s.substr(i, 10);

            freq[sub]++;

            if (freq[sub] == 2) {
                ans.push_back(sub);
            }
        }

        return ans;
    }
};