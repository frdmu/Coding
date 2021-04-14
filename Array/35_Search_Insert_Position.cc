// https://leetcode-cn.com/problems/search-insert-position/
// solution: greedy & binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    /*  int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= target) {
                return i;
            } 
        }
        return n;
    */
        int n = nums.size(); 
        int low = 0, high = n;
        while (low < high) {
            int mid = low + ((high - low) >> 1); 
            if (nums[mid] == target) 
                return mid;
            if (nums[mid] > target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};
