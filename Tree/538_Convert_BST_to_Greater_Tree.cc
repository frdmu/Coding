// https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
// Solution: reverse in-order traversal
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
    int pre = 0;
    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;

        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};

class Solution {
public:
    int pre = 0;
    void traversal(TreeNode* cur) {
        stack<TreeNode*> stk;
        if (cur)
            stk.push(cur);
        while (!stk.empty()) {
            TreeNode* top = stk.top();
            stk.pop();
            if (top) {
                if (top->left)
                    stk.push(top->left);
                stk.push(top);
                stk.push(nullptr); 
                if (top->right)
                    stk.push(top->right);
            } else {
                TreeNode* top = stk.top();
                stk.pop();
                top->val += pre;
                pre = top->val;
            }
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};
