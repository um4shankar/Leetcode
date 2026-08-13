class Solution {
public:
    int bSearch(int l, int r, vector<int>& nums, int target) {
        if (l > r) return l;
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            return bSearch(mid + 1, r, nums, target);

        return bSearch(l, mid - 1, nums, target);
    }

    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        return bSearch(l, r, nums, target);
    }
};