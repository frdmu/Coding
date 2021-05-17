// https://leetcode-cn.com/problems/validate-binary-search-tree/
// Solution: traverse BST in inOrder, the value of element is getting bigger and bigger. 
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
    void inOrder(TreeNode* root, vector<int>& vec) {
        if (root == nullptr)
            return;
        
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);
        
        int len = vec.size();
        for (int i = 0; i < len-1; i++) {
            if (vec[i] >= vec[i+1])
                return false;
        }

        return true;
    }
};

class Solution {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;

        bool left = isValidBST(root->left);
        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);

        return left && right;
    }
};
