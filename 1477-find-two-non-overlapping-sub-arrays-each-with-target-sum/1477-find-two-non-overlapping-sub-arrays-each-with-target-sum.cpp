class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int answer = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                // Combine current subarray with the best
                // subarray ending before 'left'
                if (left > 0 && best[left - 1] != INF) {
                    answer = min(answer, len + best[left - 1]);
                }

                // Store the shortest valid subarray ending at or before right
                if (right == 0)
                    best[right] = len;
                else
                    best[right] = min(best[right - 1], len);
            }
            else {
                if (right > 0)
                    best[right] = best[right - 1];
            }
        }

        return answer == INF ? -1 : answer;
    }
};