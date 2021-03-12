// https://leetcode-cn.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        set<vector<int>>  ans;

        int len = nums.size();
        if (len < 3)
            return {};

        sort(nums.begin(), nums.end());
        for (int i = 0; i < len -2; i++) {
            int k = len - 1;
            int j = i + 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.insert({nums[i], nums[j++], nums[k--]});
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        for (auto item : ans) {
            res.push_back(item);
        }

        return res;
    }
};