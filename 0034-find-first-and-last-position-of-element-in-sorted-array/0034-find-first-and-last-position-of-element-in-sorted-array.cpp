class Solution {
public:
    int biSearch(vector<int>& nums, int l, int r, int target) {
        if (l > r)
            return -1;

        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
            return mid;

        if (target < nums[mid])
            return biSearch(nums, l, mid - 1, target);

        return biSearch(nums, mid + 1, r, target);
    }

    int leftEnd(vector<int>& nums, int l, int r, int target) {
        if (l == r)
            return l;

        int mid = l + (r - l) / 2;

        if (nums[mid] < target)
            return leftEnd(nums, mid + 1, r, target);

        return leftEnd(nums, l, mid, target);
    }

    int rightEnd(vector<int>& nums, int l, int r, int target) {
        if (l == r)
            return l;

        int mid = l + (r - l + 1) / 2;

        if (nums[mid] > target)
            return rightEnd(nums, l, mid - 1, target);

        return rightEnd(nums, mid, r, target);
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        if (n == 0)
            return {-1, -1};

        int p = biSearch(nums, 0, n - 1, target);

        if (p == -1)
            return {-1, -1};

        int Left = leftEnd(nums, 0, p, target);
        int Right = rightEnd(nums, p, n - 1, target);

        return {Left, Right};
    }
};