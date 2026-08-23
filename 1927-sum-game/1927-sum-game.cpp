class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int diff = 0;
        int qLeft = 0;
        int qRight = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                qLeft++;
            else
                diff += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                qRight++;
            else
                diff -= num[i] - '0';
        }

        // Odd number of '?' -> Alice wins
        if ((qLeft + qRight) % 2 == 1)
            return true;

        // Bob can force equality only in this exact situation
        if (diff * 2 == 9 * (qRight - qLeft))
            return false;

        return true;
    }
};