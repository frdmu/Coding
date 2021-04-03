// https://leetcode-cn.com/problems/sort-transformed-array/
// solution: after transformed, the numbers sorted in some order, so we can use two pointers!
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int len = nums.size();
        vector<int> vec(len);
        int index = a > 0 ? len-1: 0; 

        for (int i = 0; i < len; i++) {
            nums[i] = a * nums[i] * nums[i] + b * nums[i] + c;
        }
        int i = 0, j = len - 1;
        while (i <= j) {
            if (a > 0) {
                if (nums[i] > nums[j]) {
                    vec[index--] = nums[i++];
                } else {
                    vec[index--] = nums[j--];
                }
            } else {
                if (nums[i] < nums[j]) {
                    vec[index++] = nums[i++];
                } else {
                    vec[index++] = nums[j--];
                }
            }
        }

        return vec;
    }
};
