
class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;

        vector<int> s(n + 1);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int count = 1;
        int head = 2;
        int tail = 3;
        int num = 1;

        while (tail < n) {
            int freq = s[head];

            for (int j = 0; j < freq && tail < n; j++) {
                s[tail++] = num;

                if (num == 1) {
                    count++;
                }
            }

            num = 3 - num;
            head++;
        }

        return count;
    }
};
