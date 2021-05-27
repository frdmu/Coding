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

class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracing(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracing(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracing(nums, used);
        return ans;
    }
};
