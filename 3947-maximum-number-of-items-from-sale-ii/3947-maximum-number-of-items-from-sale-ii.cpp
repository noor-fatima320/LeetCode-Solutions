
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        sort(items.begin(), items.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        int mx = 0;

        for (auto& item : items) {
            mx = max(mx, item[0]);
        }

        vector<int> freq(mx + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        for (int i = 1; i <= mx; i++) {
            for (int j = 2 * i; j <= mx; j += i) {
                freq[i] += freq[j];
            }
        }

        long long minPrice = items[0][1];
        long long remaining = budget;
        long long ans = 0;

        for (auto& item : items) {
            long long price = item[1];

            if (price >= 2 * minPrice)
                break;

            long long gain = freq[item[0]] - 1;

            long long take = min(gain, remaining / price);

            ans += 2 * take;
            remaining -= take * price;
        }

        ans += remaining / minPrice;

        return (int)ans;
    }
};
