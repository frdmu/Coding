// https://leetcode-cn.com/problems/chuan-di-xin-xi/
// dfs
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> graph(n);
        for (auto &edge: relation) {
            int src = edge[0], end = edge[1];
            graph[src].push_back(end);
        } 

        int res = 0;
        dfs(res, 0, 0, n, graph, k);
        return res; 
    }
    void dfs(int& res, int step, int cur, int n, vector<vector<int>>& graph, int k) {
        if (step == k) {
            if (cur == n-1)
                res++;
            return;
        }
        for (auto to: graph[cur]) {
            dfs(res, step+1, to, n, graph, k);
        }
    }
    
};
