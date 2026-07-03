class Solution {
public:
    void InOrder(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;
        InOrder(root->left, ans);
        ans.push_back(root->val);
        InOrder(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        InOrder(root, ans);

        int n = ans.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            if (ans[l] + ans[r] > k) {
                r--;
            }
            else if (ans[l] + ans[r] < k) {
                l++;
            }
            else {
                return true;
            }
        }

        return false;
    }
};