// https://leetcode-cn.com/problems/combinations/
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    void backtracing(int n, int k, int startIndex) {
        if (path.size() == k) {
            ans.push_back(path);
            return; 
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);
            backtracing(n, k, i+1); 
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracing(n, k, 1);
        return ans;
    }
};
