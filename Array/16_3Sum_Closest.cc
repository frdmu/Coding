// https://leetcode-cn.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int sub = INT_MAX;
        int ans = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < len-2; i++) {
            for (int j = i+1; j < len-1; j++) {
                for (int k = j+1; k < len; k++) {
                    int tmpsum = nums[i] + nums[j] + nums[k]; 
                    if (abs(target-tmpsum) < sub) {
                        ans = tmpsum; 
                        sub = abs(target - tmpsum);
                    }
                }
            }
        }

        return ans;
    }
};
