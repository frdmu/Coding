// https://leetcode-cn.com/problems/combination-sum-ii/
// solution: backtrace, sort to solve duplicate
class Solution {
public:
    void dfs(vector<vector<int> >& ans, vector<int>& tmp, int index, vector<int>& candidates, int target) {
        if (target < 0) return;
        int n = candidates.size();
        if (target == 0) {
            ans.push_back(tmp);
            return;
        }

        for (int i = index; i < n; i++) {
            if (i > index && candidates[i] == candidates[i-1])
                continue;
            tmp.push_back(candidates[i]);
            dfs(ans, tmp, i+1, candidates, target-candidates[i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> tmp;

        sort(candidates.begin(), candidates.end());
        dfs(ans, tmp, 0, candidates, target);

        return ans;
    }
};

class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracing(vector<int> candidates, int target, int sum, int startIndex, vector<bool>& visited) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum+candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i-1] && visited[i-1] == false) continue;
            visited[i] = 1;
            path.push_back(candidates[i]);
            backtracing(candidates, target, sum+candidates[i], i+1, visited);
            path.pop_back();
            visited[i] = 0;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> visited(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracing(candidates, target, 0, 0, visited);
        return ans;
    }
};
