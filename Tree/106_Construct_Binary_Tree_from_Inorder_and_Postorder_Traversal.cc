// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* traversal(vector<int> inorder, int inorderStart, int inorderEnd, vector<int> postorder, int postorderStart, int postorderEnd) {
        if (postorderStart == postorderEnd) return nullptr;
        
        int value = postorder[postorderEnd-1];
        TreeNode* root = new TreeNode(value);
        if (postorderEnd - postorderStart == 1) return root;

        int index;
        for (index = inorderStart; index < inorderEnd; index++) {
            if (inorder[index] == value) break;
        } 

        int leftInorderStart = inorderStart;
        int leftInorderEnd = index;
        int leftPostorderStart = postorderStart;
        int leftPostorderEnd = leftPostorderStart + (leftInorderEnd - inorderStart);

        int rightInorderStart = index + 1;
        int rightInorderEnd = inorderEnd;
        int rightPostorderStart = leftPostorderEnd;
        int rightPostorderEnd = postorderEnd - 1;

        root->left = traversal(inorder, leftInorderStart, leftInorderEnd, postorder, leftPostorderStart, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderStart, rightInorderEnd, postorder, rightPostorderStart, rightPostorderEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
