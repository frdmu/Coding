// https://leetcode-cn.com/problems/4sum/
class Solution {
public:
    unordered_map<int, int> hashtable; 
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        int len = nums.size();
        if (len < 4) return {};

        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            hashtable[nums[i]] = i;
        } 
        for (int i = 0; i < len-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; 
            threeSum(nums, i+1, len, target-nums[i], nums[i], ans);
        }        

        return ans;
    }
    
    void threeSum(vector<int>& nums, int start, int len, int target, int cur, vector<vector<int>>& ans) {
        for (int i = start; i < len-2; i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < len-1; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                auto it = hashtable.find(target-nums[i]-nums[j]);
                if (it != hashtable.end() && it->second > j) {
                    ans.push_back({cur, nums[i], nums[j], it->first});
                }
            }
        }
    }
};
