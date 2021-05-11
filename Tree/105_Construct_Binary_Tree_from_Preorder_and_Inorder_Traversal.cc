// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* traversal(vector<int> preorder, int preorderStart, int preorderEnd, vector<int> inorder, int inorderStart, int inorderEnd) {
        if (preorderStart == preorderEnd) return nullptr;

        int value = preorder[preorderStart];
        TreeNode* root = new TreeNode(value);
        if (preorderEnd - preorderStart == 1) return root;

        int index;
        for (index = inorderStart; index < inorderEnd; index++) {
            if (inorder[index] == value) break;
        }

        int leftInorderStart = inorderStart;
        int leftInorderEnd = index; 
        int leftPreorderStart = preorderStart + 1;
        int leftPreorderEnd = leftPreorderStart + (leftInorderEnd - leftInorderStart);

        int rightInorderStart = index + 1;
        int rightInorderEnd = inorderEnd; 
        int rightPreorderStart = leftPreorderEnd;
        int rightPreorderEnd = preorderEnd;
        
        root->left = traversal(preorder, leftPreorderStart, leftPreorderEnd, inorder, leftInorderStart, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderStart, rightPreorderEnd, inorder, rightInorderStart, rightInorderEnd);
    
        return root; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
