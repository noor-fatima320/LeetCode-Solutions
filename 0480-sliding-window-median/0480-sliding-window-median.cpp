
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long> low, high;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                auto it = prev(low.end());
                high.insert(*it);
                low.erase(it);
            }

            while (low.size() < high.size()) {
                auto it = high.begin();
                low.insert(*it);
                high.erase(it);
            }
        };

        auto add = [&](long long x) {
            if (low.empty() || x <= *prev(low.end())) {
                low.insert(x);
            } else {
                high.insert(x);
            }
            balance();
        };

        auto remove = [&](long long x) {
            auto it = low.find(x);

            if (it != low.end()) {
                low.erase(it);
            } else {
                it = high.find(x);
                if (it != high.end()) {
                    high.erase(it);
                }
            }

            balance();
        };

        auto getMedian = [&]() -> double {
            if (k % 2 == 1) {
                return (double)*prev(low.end());
            }

            return ((double)*prev(low.end()) +
                    (double)*high.begin()) / 2.0;
        };

        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);

            if (i >= k - 1) {
                ans.push_back(getMedian());

                remove(nums[i - k + 1]);
            }
        }

        return ans;
    }
};
