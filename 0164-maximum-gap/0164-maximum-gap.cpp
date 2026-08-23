class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        if (minVal == maxVal)
            return 0;

        // Minimum possible gap between buckets
        int gap = (maxVal - minVal + n - 2) / (n - 1);

        int bucketCount = (maxVal - minVal) / gap + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);

        // Put numbers into buckets
        for (int num : nums) {
            int index = (num - minVal) / gap;

            bucketMin[index] = min(bucketMin[index], num);
            bucketMax[index] = max(bucketMax[index], num);
            used[index] = true;
        }

        int answer = 0;
        int previousMax = minVal;

        // Find maximum gap between buckets
        for (int i = 0; i < bucketCount; i++) {
            if (!used[i])
                continue;

            answer = max(answer, bucketMin[i] - previousMax);
            previousMax = bucketMax[i];
        }

        return answer;
    }
};