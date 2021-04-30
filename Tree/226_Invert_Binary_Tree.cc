// https://leetcode-cn.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right); 
        return root;
    }
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* tmp = stk.top();
            stk.pop();
            if (tmp) {
                if (tmp->right)
                    stk.push(tmp->right);
                if (tmp->left)
                    stk.push(tmp->left);
                stk.push(tmp);
                stk.push(nullptr);
            } else {
                TreeNode* tmp = stk.top();
                stk.pop();
                swap(tmp->left, tmp->right);
            }
        }
        return root;
    }
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            swap(tmp->left, tmp->right);
            if (tmp->right)
                q.push(tmp->right);
            if (tmp->left)
                q.push(tmp->left);
        }
        return root;
    }
};
