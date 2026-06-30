class Solution {
public:
    vector<int> side;

    void bfs(TreeNode* root) {
        if (root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left)
                    q.push(cur->left);

                if (cur->right)
                    q.push(cur->right);

                if (i == sz - 1)
                    side.push_back(cur->val);
            }
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        side.clear();
        bfs(root);
        return side;
    }
};