
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freeCount(n, 0);

        // Count free items for every item type
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[i][0] != 0 &&
                    items[j][0] % items[i][0] == 0) {
                    freeCount[i]++;
                }
            }
        }

        // Group items by price
        vector<vector<int>> groups(1501);

        for (int i = 0; i < n; i++) {
            groups[items[i][1]].push_back(freeCount[i]);
        }

        const int NEG = -1000000000;

        // dp[c] = maximum value using items
        // whose prices are greater than current price
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;

        // Process prices from high to low
        for (int p = 1500; p >= 1; p--) {

            if (groups[p].empty()) continue;

            // Choose items with maximum free benefit first
            sort(groups[p].rbegin(), groups[p].rend());

            vector<int> prefix(groups[p].size() + 1, 0);

            for (int i = 0; i < groups[p].size(); i++) {
                prefix[i + 1] = prefix[i] + groups[p][i];
            }

            // Select at least one item of price p
            for (int c = 0; c <= budget; c++) {
                if (dp[c] == NEG) continue;

                int maxK = min(
                    (int)groups[p].size(),
                    (budget - c) / p
                );

                for (int k = 1; k <= maxK; k++) {

                    int remainingCopies = (budget - c) / p;

                    int total = dp[c] +
                                prefix[k] +
                                remainingCopies;

                    ans = max(ans, total);
                }
            }

            // Add current price items to 0/1 knapsack
            for (int benefit : groups[p]) {
                int cost = p;
                int value = 1 + benefit;

                for (int c = budget; c >= cost; c--) {
                    if (dp[c - cost] != NEG) {
                        dp[c] = max(
                            dp[c],
                            dp[c - cost] + value
                        );
                    }
                }
            }
        }

        return ans;
    }
};
