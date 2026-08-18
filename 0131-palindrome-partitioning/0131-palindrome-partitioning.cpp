class Solution {
public:

    vector<vector<string>> result;
    vector<string> current;

    bool isPalindrome(string& s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s, int start) {

        // Entire string has been partitioned
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        // Try every possible substring
        for (int end = start; end < s.length(); end++) {

            // Only choose palindrome substring
            if (isPalindrome(s, start, end)) {

                // Choose
                current.push_back(s.substr(start, end - start + 1));

                // Explore
                backtrack(s, end + 1);

                // Undo choice
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        backtrack(s, 0);

        return result;
    }
};