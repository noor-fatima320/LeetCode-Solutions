
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();

        bool lower = false, upper = false, digit = false;

        for (char c : password) {
            if (islower(c)) lower = true;
            if (isupper(c)) upper = true;
            if (isdigit(c)) digit = true;
        }

        int missing = (!lower) + (!upper) + (!digit);

        int replace = 0;
        int one = 0, two = 0;

        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && password[j] == password[i]) {
                j++;
            }

            int len = j - i;

            if (len >= 3) {
                replace += len / 3;

                if (len % 3 == 0) one++;
                else if (len % 3 == 1) two++;
            }

            i = j;
        }

        if (n < 6) {
            return max(missing, 6 - n);
        }

        if (n <= 20) {
            return max(missing, replace);
        }

        int remove = n - 20;
        replace -= min(remove, one);
        replace -= min(max(0, remove - one), two * 2) / 2;
        replace -= max(0, remove - one - two * 2) / 3;

        return remove + max(missing, replace);
    }
};
