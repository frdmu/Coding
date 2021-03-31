// https://leetcode-cn.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int, int> hashmap;
        
        for (int i = 0; i < len; i++) {
            auto it = hashmap.find(target - nums[i]);   
            if (it != hashmap.end()) {
                return {it->second, i};
            }
            hashmap[nums[i]] = i;
        }

        return {};
    }
};
