class Solution {
public:
    vector<int> dp;

    int func(int i, int n) {
        if (i == n) return 1;
        if (i > n) return 0;

        if (dp[i] != -1) return dp[i];
        return dp[i] = func(i + 1, n) + func(i + 2, n);
    }

    int climbStairs(int n) {
        dp.assign(n + 1, -1);
        return func(0, n);
    }
};