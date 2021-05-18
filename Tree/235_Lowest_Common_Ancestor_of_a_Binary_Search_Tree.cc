// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
        if (root == p || root == q || root == nullptr)
            return root;
        
        TreeNode* left = lowestCommonAncestor1(root->left, p, q);
        TreeNode* right = lowestCommonAncestor1(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        } else if (left != nullptr && right == nullptr) {
            return left;
        } else if (left == nullptr && right != nullptr) {
            return right;
        } else {
            return nullptr;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCommonAncestor1(root, p, q);
    }
};


class Solution {
public:
    TreeNode* preOrder(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val) {
            TreeNode* left = preOrder(root->left, p, q);
            if (left)
                return left;
        }

        if (root->val < p->val && root->val < q->val) {
            TreeNode* right = preOrder(root->right, p, q);
            if (right)
                return right;
        }

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return preOrder(root, p, q);
    }
};
