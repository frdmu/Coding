// https://leetcode-cn.com/problems/path-sum/
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
    void preOrder(TreeNode* root, int targetSum, vector<int>& path, bool& flag) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            int size = path.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                sum += path[i];
            }
            if (sum == targetSum) {
                flag = true;
            }
            return; 
        }
        
        if (root->left) {
            preOrder(root->left, targetSum, path, flag);
            path.pop_back(); // backtrace
        }
        if (root->right) {
            preOrder(root->right, targetSum, path, flag);
            path.pop_back(); // bracktrace
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        vector<int> path; 
        if (root == nullptr)
            return false;
        preOrder(root, targetSum, path, flag);
        return flag;
    }
};
