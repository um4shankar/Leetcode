class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r) {
    if (l > r)
        return NULL;

    int mid = (l + r) / 2;

    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums, l, mid - 1);
    root->right = build(nums, mid + 1, r);

    return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid = (l + r) / 2;
        return build(nums, l,r);
    }
};