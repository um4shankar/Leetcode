class Solution {
public:
    vector<int> dp;

    int lis(int i, vector<int>& nums) {
        if (dp[i] != -1) return dp[i];
        int ans = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                ans = max(ans, lis(j, nums) + 1);
            }
        }
        return dp[i] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        dp.assign(N, -1);
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            ans = max(ans, lis(i, nums));
        }
        return ans;
    }
};