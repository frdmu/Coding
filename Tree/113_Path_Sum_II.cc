// https://leetcode-cn.com/problems/path-sum-ii/
class Solution {
public:
    void preOrder(TreeNode* root, int targetSum, vector<int> &path, vector<vector<int> >& ans) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            int size = path.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                sum += path[i];
            }
            if (sum == targetSum) {
                ans.push_back(path);
            }
            return;
        }
        
        if (root->left) {
            preOrder(root->left, targetSum, path, ans);
            path.pop_back();
        }
        if (root->right) {
            preOrder(root->right, targetSum, path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int> > ans;
        if (root == nullptr)
            return {}; 
        
	preOrder(root, targetSum, path, ans);
        
	return ans;
    }
};
