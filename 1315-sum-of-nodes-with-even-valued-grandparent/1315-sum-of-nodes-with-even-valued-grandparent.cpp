class Solution {
public:
    int sum = 0;

    void dfs(TreeNode* root, TreeNode* parent, TreeNode* Grandparent) {
        if (root == NULL)
            return;

        if (Grandparent != NULL && Grandparent->val % 2 == 0) {
            sum += root->val;
        }

        dfs(root->left, root, parent);
        dfs(root->right, root, parent);
    }

    int sumEvenGrandparent(TreeNode* root) {
        sum = 0;
        dfs(root, NULL, NULL);
        return sum;
    }
};