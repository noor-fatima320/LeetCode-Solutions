class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> pathLength(input.size() + 1, 0);
        int maxLength = 0;
        int i = 0;

        while (i < input.size()) {
            int level = 0;

            while (i < input.size() && input[i] == '\t') {
                level++;
                i++;
            }

            int length = 0;
            bool isFile = false;

            while (i < input.size() && input[i] != '\n') {
                if (input[i] == '.') {
                    isFile = true;
                }

                length++;
                i++;
            }

            pathLength[level + 1] =
                pathLength[level] + length + 1;

            if (isFile) {
                maxLength = max(maxLength,
                                pathLength[level] + length);
            }

            i++;
        }

        return maxLength;
    }
};