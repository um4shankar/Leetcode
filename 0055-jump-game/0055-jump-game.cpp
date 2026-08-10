class Solution {
public:
    bool solve(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx == nums.size() - 1) {
            return true;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        if (nums[idx] == 0) {
            return dp[idx] = false;
        }

        for (int jump = 1; jump <= nums[idx]; jump++) {
            if (idx + jump < nums.size()) {
                if (solve(nums, idx + jump, dp)) {
                    return dp[idx] = true;
                }
            }
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};