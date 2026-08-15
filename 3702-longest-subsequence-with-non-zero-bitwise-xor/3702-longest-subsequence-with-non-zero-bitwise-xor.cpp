class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();
        int totalXor = 0;

        // Puri array ka XOR
        for (int num : nums) {
            totalXor ^= num;
        }

        // Agar total XOR non-zero hai,
        // puri array hi valid subsequence hai
        if (totalXor != 0) {
            return n;
        }

        // Total XOR zero hai.
        // Agar koi non-zero element hai,
        // us element ko remove karke XOR non-zero ho jayega.
        for (int num : nums) {
            if (num != 0) {
                return n - 1;
            }
        }

        // Sab elements zero hain
        return 0;
    }
};