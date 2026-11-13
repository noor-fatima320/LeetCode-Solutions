
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        struct Node {
            long long val, cnt, sum;
        };

        deque<Node> dq;
        long long cost = 0;
        long long ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            
            long long x = nums[l];
            long long cnt = 1;
            long long sum = x;

            while (!dq.empty() && dq.back().val < x) {
                cost += (x - dq.back().val) * dq.back().cnt;
                cnt += dq.back().cnt;
                sum += dq.back().sum;
                dq.pop_back();
            }

            dq.push_back({x, cnt, sum});

            while (cost > k) {
                cost -= dq.front().val - nums[r];
                dq.front().cnt--;
                dq.front().sum -= nums[r];

                if (dq.front().cnt == 0) {
                    dq.pop_front();
                }

                r--;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};
