// https://leetcode-cn.com/problems/wiggle-subsequence/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int curDiff = 0;
        int preDiff = 0;
        int ans = 1; 
        for (int i = 0; i < nums.size()-1; i++) {
            curDiff = nums[i+1] - nums[i];
            if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0) && preDiff >= 0) {
                ans++;
                preDiff = curDiff;
            }
        }

        return ans;
    }
};
