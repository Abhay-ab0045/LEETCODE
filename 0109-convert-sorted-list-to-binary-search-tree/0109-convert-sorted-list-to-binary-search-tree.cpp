/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* curr;

    TreeNode* buildBST(int n) {
        if (n <= 0)
            return NULL;

        TreeNode* leftSubtree = buildBST(n / 2);

        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;

        TreeNode* rightSubtree = buildBST(n - n / 2 - 1);

        root->left = leftSubtree;
        root->right = rightSubtree;

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        curr = head;

        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        return buildBST(n);
    }
};