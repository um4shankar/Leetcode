class Solution {
    int res = 0;
    int sum = 0;
    int cnt = 0;

public:
    void preorder(TreeNode* node) {
        if(!node) return;

        sum += node->val;
        cnt++;

        preorder(node->left);
        preorder(node->right);
    }

    void levelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        if(root) q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            sum = 0;
            cnt = 0;
            preorder(node);
            if(cnt != 0 && sum / cnt == node->val) {
                res++;
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }

    int averageOfSubtree(TreeNode* root) {
        levelOrder(root);
        return res;
    }
};