// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Soultion: from down to top, postOrder, backtrace
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr) return root;
        
        TreeNode* left = lowestCommonAncestor1(root->left, p, q);
        TreeNode* right = lowestCommonAncestor1(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        } else if (left == nullptr && right != nullptr) {
            return right;
        } else if (left != nullptr && right == nullptr) {
            return left;
        } else {
            return nullptr;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCommonAncestor1(root, p, q);
    }
};
