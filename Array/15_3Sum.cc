// https://leetcode-cn.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans; 
        unordered_map<int, int> mp;
        int len = nums.size();
        if (len < 3) return {};
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            mp[nums[i]] = i;
        }         
        for (int i = 0; i < len-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < len-1; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                auto it = mp.find(0-nums[i]-nums[j]);
                if (it != mp.end() && it->second > j) {
                    ans.push_back({nums[i], nums[j], it->first});
                }
            }
        }

        return ans;
    }
};
