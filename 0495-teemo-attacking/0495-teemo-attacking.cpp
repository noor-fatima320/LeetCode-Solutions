
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;

        for (int i = 0; i < timeSeries.size(); i++) {
            if (i == timeSeries.size() - 1) {
                ans += duration;
            } 
            else {
                ans += min(duration, timeSeries[i + 1] - timeSeries[i]);
            }
        }

        return ans;
    }
};
