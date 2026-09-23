class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        vector<int> postfixSum(n + 1, 0);

        for(int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
            postfixSum[i + 1] = postfixSum[i] + nums[n - 1 - i];
        }

        int ans = INT_MAX;
        for(int i = 0; i <= n; ++i) {
            int target = x - prefixSum[i];
            auto it = lower_bound(postfixSum.begin(), postfixSum.end(), target);
            if(it != postfixSum.end() && *it == target) {
                int j = it - postfixSum.begin();
                if(i + j <= n)
                    ans = min(ans, i + j);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};