// https://leetcode-cn.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT32_MIN;
        int count = 0; 
        
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > ans)
                ans = count;
            if (count < 0) count = 0;
        }

        return ans;
    }
};
