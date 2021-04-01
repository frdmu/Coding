// https://leetcode-cn.com/problems/3sum-smaller/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        int ans = 0;

        for (int i = 0; i < len-2; i++) {
            for (int j = i+1; j < len-1; j++) {
                for (int k = j+1; k < len; k++) {
                    if (nums[i] + nums[j] + nums[k] < target)
                        ans++;
                }
            }
        }

        return ans;
    }
};
