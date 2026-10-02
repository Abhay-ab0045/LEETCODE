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

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    int inStart, int inEnd) {
        
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);

        int inRoot = mp[rootValue];
        int leftSize = inRoot - inStart;

        root->left = build(preorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           inRoot - 1);

        root->right = build(preorder,
                            preStart + leftSize + 1,
                            preEnd,
                            inRoot + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1,
                     0, inorder.size() - 1);
    }
};