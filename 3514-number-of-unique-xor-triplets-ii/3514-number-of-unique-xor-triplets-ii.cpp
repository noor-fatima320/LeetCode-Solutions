class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // Special case
        if (n == 1)
            return 1;

        unordered_set<int> pairXor;
        unordered_set<int> tripletXor;

        // Store all unique pair XORs
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        // Combine each pair XOR with every element
        for (int x : pairXor) {
            for (int num : nums) {
                tripletXor.insert(x ^ num);
            }
        }

        return tripletXor.size();
    }
};