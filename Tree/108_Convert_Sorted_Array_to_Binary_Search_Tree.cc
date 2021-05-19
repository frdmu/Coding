// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* constructBST(vector<int>& nums, int low, int high) {
        if (low >= high) return nullptr;
        
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = constructBST(nums, low, mid);
        root->right = constructBST(nums, mid+1, high);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) { 
        int len = nums.size();
        return constructBST(nums, 0, len);
    }
};
