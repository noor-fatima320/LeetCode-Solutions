class Solution {
public:
int countPrimes(int n) {
if (n <= 2) {
return 0;
}
    vector<bool> composite(n, false);

    int count = 1; // 2 is prime

    for (int i = 3; i < n; i += 2) {
        if (!composite[i]) {
            count++;

            if ((long long)i * i < n) {
                for (int j = i * i; j < n; j += 2 * i) {
                    composite[j] = true;
                }
            }
        }
    }

    return count;
}
};
