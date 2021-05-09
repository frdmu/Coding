// https://leetcode-cn.com/problems/binary-tree-paths/
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
    vector<string> ans;
    void preorder(TreeNode* root, vector<int>& path, vector<string>& ans) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            int size = path.size();
            string tmp; 
            int i; 
            for (i = 0; i < size-1; i++) {
                tmp += to_string(path[i]);
                tmp += "->"; 
            }
            tmp += to_string(path[i]);
            ans.push_back(tmp);
            return;
        }

        if (root->left) {
            preorder(root->left, path, ans);
            path.pop_back(); // backtrace
        }
        if (root->right) {
            preorder(root->right, path, ans);
            path.pop_back(); // backtrace
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        if (root == nullptr)
            return ans;  
        preorder(root, path, ans);
        return ans;
    }
};

class Solution {
public:
    vector<string> ans;
    void preorder(TreeNode* root, string path, vector<string>& ans) {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        if (root->left) {
            preorder(root->left, path+"->", ans);
        }
        if (root->right) {
            preorder(root->right, path+"->", ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        if (root == nullptr)
            return ans;
        preorder(root, path, ans);
        return ans;
    }
};


