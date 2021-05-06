// https://leetcode-cn.com/problems/remove-element/
// solution: quick and slow pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(); 
        int lowIndex = 0;
        
        for (int fastIndex = 0; fastIndex < n; fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[lowIndex++] = nums[fastIndex];
            }
        }
        
        return lowIndex;
    }
};
