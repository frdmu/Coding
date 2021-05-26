// https://leetcode-cn.com/problems/subsets/
class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracing(vector<int>& nums, int startIndex) {
        ans.push_back(path);
        if (startIndex == nums.size()) return;
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracing(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracing(nums, 0);
        return ans;
    }
};
