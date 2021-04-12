// https://leetcode-cn.com/problems/remove-element/
// solution: quick and slow pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size(); 
        for (int j = 0; j < n; j++) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};