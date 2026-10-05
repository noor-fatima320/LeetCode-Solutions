class Solution {
public:
int nthSuperUglyNumber(int n, vector<int>& primes) {
vector<int> ugly(n);
ugly[0] = 1;

    int m = primes.size();

    vector<int> index(m, 0);
    vector<long long> next(m);

    for (int i = 0; i < m; i++) {
        next[i] = primes[i];
    }

    for (int i = 1; i < n; i++) {
        long long minimum = next[0];

        for (int j = 1; j < m; j++) {
            minimum = min(minimum, next[j]);
        }

        ugly[i] = (int)minimum;

        for (int j = 0; j < m; j++) {
            if (next[j] == minimum) {
                index[j]++;
                next[j] = (long long)ugly[index[j]] * primes[j];
            }
        }
    }

    return ugly[n - 1];
}

};