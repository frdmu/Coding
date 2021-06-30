// https://leetcode-cn.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        if (n == 1) return 0;
        int cover = 0;
        int i = 0;

        cover = max(0+nums[0], cover);
        if (cover >= n-1) return 1;
        while (i <= cover) {
            int max = -1; 
            int tmp = -1;
            for (int j = ++i; j <= cover; j++) {
                if (j + nums[j] > max) {
                    max = j + nums[j];
                    tmp = j;
                }
            } 

            i = tmp;
            cover = max;    
            res++;
            if (cover >= n-1) 
                break;    
        }

        return ++res;
    }
};
