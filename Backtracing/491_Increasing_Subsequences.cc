// https://leetcode-cn.com/problems/increasing-subsequences/
class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracing(vector<int> nums, int startIndex) {
        if (path.size() > 1) {
            ans.push_back(path);
        }

        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) {
                continue;    
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracing(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracing(nums, 0);
        return ans;
    }
};

class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracing(vector<int> nums, int startIndex) {
        if (path.size() > 1) {
            ans.push_back(path);
        }

        int used[201] = {0};
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || used[nums[i]+100] != 0) {
                continue;
            }
            used[nums[i]+100] = 1;
            path.push_back(nums[i]);
            backtracing(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracing(nums, 0);
        return ans;
    }
};
