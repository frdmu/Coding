// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
// solution: recursive
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));             
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->right)
                    q.push(tmp->right);
                if (tmp->left)
                    q.push(tmp->left);
            }
            depth++;
        }

        return depth;
    }
};
