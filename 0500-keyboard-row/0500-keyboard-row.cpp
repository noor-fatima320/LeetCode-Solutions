class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> ans;

        for (string word : words) {
            int row = 0;
            bool valid = true;

            for (char c : word) {
                c = tolower(c);

                int current;

                if (row1.find(c) != string::npos)
                    current = 1;
                else if (row2.find(c) != string::npos)
                    current = 2;
                else
                    current = 3;

                if (row == 0)
                    row = current;
                else if (row != current) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans.push_back(word);
        }

        return ans;
    }
};