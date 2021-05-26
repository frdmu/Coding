// https://leetcode-cn.com/problems/subsets-ii/
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    void backtracing(vector<int>& nums, int startIndex, vector<bool>& visited) {
        ans.push_back(path);
        if (startIndex == nums.size()) return;
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && visited[i-1] == false) {
                continue;
            } 
            path.push_back(nums[i]);
            visited[i] = true;
            backtracing(nums, i+1, visited);
            path.pop_back();
            visited[i] = false;
        }
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool>  visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracing(nums, 0, visited);
        return ans;
    }
};
