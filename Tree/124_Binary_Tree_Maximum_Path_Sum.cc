// https://leetcode-cn.com/leetbook/read/bytedance-c01/ohlfp5/
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
    int res = INT_MIN;
    int maxGain(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = max(maxGain(root->left), 0);
        int right = max(maxGain(root->right), 0);
        // 记录以每一个结点为连接点的路径，其中最大的就是最后的结果 
        int pathsum = root->val + left + right;
        res = max(res, pathsum); 
        
        return root->val + max(left, right);   
    } 
     
    int maxPathSum(TreeNode* root) { 
        maxGain(root);
        return res;  
    }
};