class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        set<int> threeSum;

        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                threeSum.insert(sum);

                if (sum < target) {
                    l++;
                }
                else if (sum > target) {
                    r--;
                }
                else {
                    return target;
                }
            }
        }

        int ans = *threeSum.begin();
        int mn = abs(ans - target);

        for (auto it : threeSum) {
            if (abs(it - target) < mn) {
                mn = abs(it - target);
                ans = it;
            }
        }

        return ans;
    }
};