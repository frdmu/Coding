// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int min_depth = INT_MAX;
        if (root->left != NULL) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != NULL) {
            min_depth = min(minDepth(root->right), min_depth);
        }
        return min_depth+1;
    }
};
// postorder 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0)
            return 1 + right;
        if (right == 0)
            return 1 + left;
        return 1 + min(left, right);
    }
};

// level order
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            depth++;
            for (int i = 0; i < len; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
                if (!tmp->left && !tmp->right)
                    return depth;
            }
        }

        return depth;
    }
};
