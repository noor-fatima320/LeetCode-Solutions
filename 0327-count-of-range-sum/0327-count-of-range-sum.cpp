class Solution {
public:

    long long mergeSort(vector<long long>& prefix,
                        vector<long long>& temp,
                        int left,
                        int right,
                        long long lower,
                        long long upper) {

        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;

        long long count = 0;

        // Count in left half and right half
        count += mergeSort(prefix, temp, left, mid, lower, upper);
        count += mergeSort(prefix, temp, mid + 1, right, lower, upper);

        // Count valid pairs across both halves
        int low = mid + 1;
        int high = mid + 1;

        for (int i = left; i <= mid; i++) {

            while (low <= right &&
                   prefix[low] - prefix[i] < lower) {
                low++;
            }

            while (high <= right &&
                   prefix[high] - prefix[i] <= upper) {
                high++;
            }

            count += high - low;
        }

        // Merge the two sorted halves
        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {

            if (prefix[i] <= prefix[j]) {
                temp[k++] = prefix[i++];
            }
            else {
                temp[k++] = prefix[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = prefix[i++];
        }

        while (j <= right) {
            temp[k++] = prefix[j++];
        }

        for (int p = left; p <= right; p++) {
            prefix[p] = temp[p];
        }

        return count;
    }

    long long countRangeSum(vector<int>& nums,
                            int lower,
                            int upper) {

        int n = nums.size();

        // Prefix sum array
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<long long> temp(n + 1);

        return mergeSort(
            prefix,
            temp,
            0,
            n,
            lower,
            upper
        );
    }
};