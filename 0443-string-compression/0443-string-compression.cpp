
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int i = 0;

        while (i < n) {
            char current = chars[i];
            int j = i;

            while (j < n && chars[j] == current) {
                j++;
            }

            chars[write++] = current;

            int count = j - i;

            if (count > 1) {
                string digits = to_string(count);

                for (char digit : digits) {
                    chars[write++] = digit;
                }
            }

            i = j;
        }

        return write;
    }
};
