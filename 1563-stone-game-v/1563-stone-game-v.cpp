class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefixSum;

    int func(int l, int r, vector<int>& stoneValue) {
        if (l >= r) return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int i = l; i < r; ++i) {
            int sumL = 0, sumR = 0;

            sumL = prefixSum[i + 1] - prefixSum[l];
            sumR = prefixSum[r + 1] - prefixSum[i + 1];

            if (sumL < sumR) {
                ans = max(ans, sumL + func(l, i, stoneValue));
            }
            else if (sumL > sumR) {
                ans = max(ans, sumR + func(i + 1, r, stoneValue));
            }
            else {
                ans = max(ans,
                    sumL + max(
                        func(l, i, stoneValue),
                        func(i + 1, r, stoneValue)
                    )
                );
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefixSum.assign(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }

        dp.assign(n, vector<int>(n, -1));

        return func(0, n - 1, stoneValue);
    }
};