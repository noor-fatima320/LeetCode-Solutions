class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        string temp = s + s;
        temp = temp.substr(1, 2 * n - 2);

        return temp.find(s) != string::npos;
    }
};