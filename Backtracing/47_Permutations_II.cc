// https://leetcode-cn.com/problems/permutations-ii/
// solution: avoid duplication by sorting nums:
//
// sort(nums.begin(), nums.end())
// if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) 
//                continue;

class Solution {
public:
    void permutation(vector<int>& tmp, vector<vector<int> >& ans, vector<int>& nums, vector<int>& visited) {
        int n = nums.size();
        if (tmp.size() == n) {
            ans.emplace_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) {
                continue;
            }
            tmp.emplace_back(nums[i]);
            visited[i] = 1;
            permutation(tmp, ans, nums, visited);
            tmp.pop_back();
            visited[i] = 0; 
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int> > ans;
        int len = nums.size();
        if (len == 0) {
            return {};
        }
        vector<int> visited(len, 0);

        sort(nums.begin(), nums.end());
        permutation(tmp, ans, nums, visited);

        return ans;
    }
};
