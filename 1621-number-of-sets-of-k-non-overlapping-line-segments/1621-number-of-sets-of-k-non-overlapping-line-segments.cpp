class Solution {
public:
    long long power(long long a, long long b) {
        long long res = 1;
        long long MOD = 1000000007;

        while (b) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int numberOfSets(int n, int k) {
        long long ans = 1;
        long long MOD = 1000000007;

        int a = n + k - 1;
        int b = 2 * k;

        for (int i = 1; i <= b; i++) {
            ans = ans * (a - b + i) % MOD;
        }

        for (int i = 1; i <= b; i++) {
            ans = ans * power(i, MOD - 2) % MOD;
        }

        return ans;
    }
};