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
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent,
                    TreeNode*& target, int start) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start)
                target = node;

            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* target = NULL;

        markParent(root, parent, target, start);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int time = 0;

        while(!q.empty()) {
            int size = q.size();
            bool burned = false;

            while(size--) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                    burned = true;
                }

                if(node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                    burned = true;
                }

                if(parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                    burned = true;
                }
            }

            if(burned)
                time++;
        }

        return time;
    }
};