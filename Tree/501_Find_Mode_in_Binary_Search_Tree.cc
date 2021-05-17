// https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
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
    vector<int> ans;
    int cnt = 0;
    int cntMax = -1;
    TreeNode* pre = nullptr;
    void inOrder(TreeNode* root) {
        if (root == nullptr)
            return;

        inOrder(root->left);
        if (pre == nullptr) {
            cnt = 1;
        } else if (pre->val == root->val) {
            cnt++;
        } else {
            cnt = 1;
        }
        pre = root;
        if (cnt == cntMax) {
            ans.push_back(pre->val);
        } 
        if (cnt > cntMax) {
            ans.clear();
            cntMax = cnt;
            ans.push_back(pre->val);
        } 

        inOrder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};
