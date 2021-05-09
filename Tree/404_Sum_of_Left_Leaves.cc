// https://leetcode-cn.com/problems/sum-of-left-leaves/

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
    void preorder(TreeNode* root, int &sum, int &flag) {
        if (flag == 0 && !root->left && !root->right) {
            sum += root->val;
            return;
        }

        if (root->left) {
            flag = 0;
            preorder(root->left, sum, flag);
        }
        if (root->right) {
            flag = -1;
            preorder(root->right, sum, flag);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        int flag = -1;
        
        if (root == nullptr) 
            return sum;
        preorder(root, sum, flag);
        
        return sum;
    }
};
