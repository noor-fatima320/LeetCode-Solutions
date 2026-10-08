class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        // Count frequency of each number
        for (int num : nums) {
            frequency[num]++;
        }

        // Bucket: index = frequency
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& pair : frequency) {
            int num = pair.first;
            int count = pair.second;

            bucket[count].push_back(num);
        }

        vector<int> answer;

        // Start from highest frequency
        for (int freq = nums.size(); freq >= 1; freq--) {
            for (int num : bucket[freq]) {
                answer.push_back(num);

                if (answer.size() == k) {
                    return answer;
                }
            }
        }

        return answer;
    }
};