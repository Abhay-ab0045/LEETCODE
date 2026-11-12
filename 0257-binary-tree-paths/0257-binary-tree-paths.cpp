/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;

    void solve(TreeNode* root, string& path) {
        if (root == NULL)
            return;

        int len = path.size();

        if (!path.empty())
            path += "->";

        path += to_string(root->val);

        // If leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
        }
        else {
            solve(root->left, path);
            solve(root->right, path);
        }

        // Backtracking
        path.resize(len);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        string path = "";

        solve(root, path);

        return ans;
    }
};