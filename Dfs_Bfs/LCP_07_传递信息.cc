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
// bfs
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> graph(n);
        for (auto &edge: relation) {
            int src = edge[0], end = edge[1];
            graph[src].push_back(end);
        }

        queue<int> q;
        q.push(0);
        int step = 0, res = 0;
        while (step <= k) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int tmp = q.front();
                q.pop();
                if (step == k && tmp == n-1) {
                    res++;
                }
                for (auto to: graph[tmp]) {
                   q.push(to);
                }
            }
            step++;
        }

        return res;
    }
};
