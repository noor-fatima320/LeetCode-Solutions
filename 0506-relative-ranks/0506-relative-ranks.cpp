
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<int> sorted = score;
        sort(sorted.rbegin(), sorted.rend());

        unordered_map<int, string> ranks;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ranks[sorted[i]] = "Gold Medal";
            }
            else if (i == 1) {
                ranks[sorted[i]] = "Silver Medal";
            }
            else if (i == 2) {
                ranks[sorted[i]] = "Bronze Medal";
            }
            else {
                ranks[sorted[i]] = to_string(i + 1);
            }
        }

        vector<string> ans;

        for (int s : score) {
            ans.push_back(ranks[s]);
        }

        return ans;
    }
};
