// https://leetcode-cn.com/problems/majority-element/
// solution: recursive
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return findMajorityElement(nums, 0, nums.size()-1);
    }
    int findMajorityElement(vector<int>& nums, int start, int end) {
        if (start == end)
            return nums[start];
        int mid = (start + end) / 2;
        int left = findMajorityElement(nums, start, mid);
        int right = findMajorityElement(nums, mid+1, end);
        if (majorityCount(nums, start, end, left) > (end - start + 1) / 2)
            return left;
        if (majorityCount(nums, start, end, right) > (end - start + 1) / 2)
            return right;
        return -1;
    }
    int majorityCount(vector<int>& nums, int start, int end, int target) {
        int cnt = 0; 
        for (int i = start; i <= end; i++) {
            if (nums[i] == target)
                cnt++;
        }
        return cnt;
    }
};
