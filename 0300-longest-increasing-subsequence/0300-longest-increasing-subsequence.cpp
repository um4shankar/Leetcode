class Solution {
public:
    vector<int> dp;
    int func(int i, vector<int>& nums){
      if(i<0) return 0;
      if(dp[i]!= -1) return dp[i];
      dp[i] = 1;
      for(int j=i-1; j>=0; --j){
        if(nums[j]<nums[i]){
            dp[i] = max(1 + func(j, nums), dp[i]);
        }
      }
      return dp[i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, func(i, nums));
        }
        return ans;
    }
};