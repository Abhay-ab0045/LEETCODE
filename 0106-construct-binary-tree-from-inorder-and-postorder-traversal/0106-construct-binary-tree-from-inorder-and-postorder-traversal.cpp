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
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd, int postStart, int postEnd) {

        if(inStart > inEnd || postStart > postEnd)
            return NULL;

        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);

        int inRoot = mp[rootValue];
        int leftSize = inRoot - inStart;

        root->right = build(inorder, postorder,
                             inRoot + 1, inEnd,
                             postStart + leftSize, postEnd - 1);

        root->left = build(inorder, postorder,
                            inStart, inRoot - 1,
                            postStart, postStart + leftSize - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(inorder, postorder,
                     0, inorder.size() - 1,
                     0, postorder.size() - 1);
    }
};