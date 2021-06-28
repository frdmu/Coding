// https://leetcode-cn.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            cover = max(i+nums[i], cover);
            if (cover >= n-1) return true;
        }

        return false;
    }
};
