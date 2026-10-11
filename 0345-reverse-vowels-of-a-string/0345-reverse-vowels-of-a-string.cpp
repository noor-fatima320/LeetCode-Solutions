class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right &&
                   tolower(s[left]) != 'a' &&
                   tolower(s[left]) != 'e' &&
                   tolower(s[left]) != 'i' &&
                   tolower(s[left]) != 'o' &&
                   tolower(s[left]) != 'u') {
                left++;
            }

            while (left < right &&
                   tolower(s[right]) != 'a' &&
                   tolower(s[right]) != 'e' &&
                   tolower(s[right]) != 'i' &&
                   tolower(s[right]) != 'o' &&
                   tolower(s[right]) != 'u') {
                right--;
            }

            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};