// https://leetcode-cn.com/problems/combination-sum-iii/
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    void backtracing(int targetSum, int k, int sum, int startIndex) {
        if (path.size() == k && sum == targetSum) {
            ans.push_back(path); 
            return;
        }
        for (int i = startIndex; i <= 9; i++) {
            path.push_back(i);
            backtracing(targetSum, k, sum+i, i+1);
            path.pop_back();
        }
    }   
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracing(n, k, 0, 1);
        return ans;
    }
};
