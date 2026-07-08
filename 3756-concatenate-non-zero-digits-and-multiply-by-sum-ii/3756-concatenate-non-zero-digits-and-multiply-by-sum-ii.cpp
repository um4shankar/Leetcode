class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefixSum(n + 1, 0);
        vector<long long> prefixNum(n + 1, 0);
        vector<int> prefixCnt(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            prefixSum[i + 1] = prefixSum[i] + d;
            prefixNum[i + 1] = prefixNum[i];
            prefixCnt[i + 1] = prefixCnt[i];

            if (d != 0) {
                prefixNum[i + 1] = (prefixNum[i] * 10 + d) % MOD;
                prefixCnt[i + 1]++;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefixSum[r + 1] - prefixSum[l];
            int cnt = prefixCnt[r + 1] - prefixCnt[l];

            if (cnt == 0) {
                ans.push_back(0);
                continue;
            }

            long long x;

            if (l == 0) {
                x = prefixNum[r + 1];
            } else {
                x = (prefixNum[r + 1] - (prefixNum[l] * pow10[cnt]) % MOD + MOD) % MOD;
            }

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};