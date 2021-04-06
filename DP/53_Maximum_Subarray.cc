// https://leetcode-cn.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int ans = nums[0]; 
        int dp = nums[0];
        
        for (int i = 1; i < len; i++) {
            dp = dp < 0 ? nums[i] : dp + nums[i];
            ans = max(ans, dp); 
        } 

        return ans;
    }
};
