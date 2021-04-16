// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
// solution: leftIndex: index of first element >= target
// 	     rightIndex: index of first element > target
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int leftIndex = 0, rightIndex = n-1; 
        int low = 0, high = n-1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
                leftIndex = mid;
            } else {
                low = mid + 1;
            } 
        }

        low = 0, high = n-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
                rightIndex = mid-1;
            } else {
                low = mid + 1;
            } 
        }

        if (leftIndex <= rightIndex && leftIndex >= 0 && rightIndex < n && nums[leftIndex] == target && nums[rightIndex] == target) {
            ans.push_back(leftIndex);
            ans.push_back(rightIndex);
            return ans;
        }
        return {-1, -1};
    }
};
