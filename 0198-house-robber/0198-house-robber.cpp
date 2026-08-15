class Solution {
public:
    vector<int> dp;
    int func(int i, vector<int>& nums){
        if(i>nums.size()-1) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = max(nums[i]+func(i+2, nums), func(i+1, nums));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        return func(0, nums);
    }
};