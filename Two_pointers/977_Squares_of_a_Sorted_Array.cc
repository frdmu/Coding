// https://leetcode-cn.com/problems/squares-of-a-sorted-array/
// solution: consider the numbers sorted in non-decreasing order, the squares of each number also have some features in order,
// that is numbers sorted in non-decresing order from two end to middle, so two pointer is a good trick to solve this problem.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len);
        int index = len - 1;
        int i = 0, j = len-1;
       
        for (int k = 0; k < len; k++) {
            nums[k] = nums[k] * nums[k];
        }
        while(i <= j) {
            if (nums[i] < nums[j]) {
                ans[index--] = nums[j--]; 
            } else {
                ans[index--] = nums[i++];
            }
        }       

        return ans; 
    }
};
