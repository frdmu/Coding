// https://leetcode-cn.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 4)
            return {};
        vector<vector<int> > ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < len-3; i++) {
            // pruning
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < len-2; j++) {
                // pruning
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j + 1;
                int right = len - 1;
                while (left < right) {
                    int tmp = nums[i] + nums[j] + nums[left] + nums[right]; 
                    if (tmp == target) {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        // pruning 
                        while (left < right && nums[left] == nums[left+1]) left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        
                        left++;
                        right--;
                    } else if (tmp < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
