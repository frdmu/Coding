// https://leetcode-cn.com/problems/delete-node-in-a-bst/
// Solution: five cases
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key) {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            cur->left = root->left;
            return root->right;
        } 

        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);

        return root; 
    }
};
