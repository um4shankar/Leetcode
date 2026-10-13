class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });

        long long sum = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            sum += 1LL * nums[l] * nums[l] - 1LL * nums[r] * nums[r];
            l++;
            r--;
        }

        if (n % 2 != 0) {
            sum += 1LL * nums[l] * nums[l];
        }

        return sum;
    }
};