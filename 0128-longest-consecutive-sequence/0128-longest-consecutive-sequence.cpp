
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {

            // Sirf sequence ke starting number se count karo
            if (st.find(num - 1) == st.end()) {

                int current = num;
                int length = 1;

                // Consecutive numbers check karo
                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};