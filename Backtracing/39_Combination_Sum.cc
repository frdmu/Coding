// https://leetcode-cn.com/problems/combination-sum/
// solution: backtrace, sort to solve duplicate
class Solution {
public:
    void dfs(vector<vector<int> >& ans, vector<int>& tmp, int index, vector<int>& candidates, int target) {
        if (target < 0) return;
        int n = candidates.size();
        if (index >= n) return; 
        if (target == 0) {
            ans.push_back(tmp);
            return;
        }
        for (int i = index; i < n; i++) {
            tmp.push_back(candidates[i]);
            dfs(ans, tmp, i, candidates, target-candidates[i]);
            tmp.pop_back();
        } 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end()); 

        dfs(ans, tmp, 0, candidates, target);
        
        return ans;
    }
};
