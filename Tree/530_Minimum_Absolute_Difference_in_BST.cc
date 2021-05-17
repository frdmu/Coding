// https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
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

    TreeNode* pre = nullptr;
    void inOrder(TreeNode* root, int &min) {
        if (root == nullptr)
            return;

        inOrder(root->left, min);
        if (pre != nullptr && abs(pre->val - root->val) < min)
            min = abs(pre->val - root->val); 
        pre = root;
        inOrder(root->right, min);
    }
    int getMinimumDifference(TreeNode* root) {
        int min = INT_MAX;
        
        inOrder(root, min);

        return min;
    }
};
