// https://leetcode-cn.com/problems/balanced-binary-tree/
// solution: tree's depth
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (abs(deep(root->left) - deep(root->right)) <= 1) {
            if (isBalanced(root->left) && isBalanced(root->right)) {
                return true;
            }
        } 
        
        return false; 
    }
    int deep(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(deep(root->left), deep(root->right));
    }
};
