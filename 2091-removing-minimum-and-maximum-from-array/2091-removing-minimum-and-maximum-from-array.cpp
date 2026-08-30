class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = 1e9, maxi = -1e9;
        int p = 0, q = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < mini) {
                mini = nums[i];
                p = i;
            }

            if (nums[i] > maxi) {
                maxi = nums[i];
                q = i;
            }
        }

        int l = min(p, q);
        int r = max(p, q);

        return min({r + 1, n - l, l + 1 + n - r});
    }
};