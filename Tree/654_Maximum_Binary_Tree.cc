// https://leetcode-cn.com/problems/maximum-binary-tree/
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
    TreeNode* traversal(vector<int> nums, int start, int end) {
        if (start == end) return nullptr;
        
        int index = start; 
        for (int i = start+1; i < end; i++) {
            if (nums[i] > nums[index]) {
                index = i;
            }
        }
        TreeNode* root = new TreeNode(nums[index]);

        root->left = traversal(nums, start, index); 
        root->right = traversal(nums, index+1, end);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
