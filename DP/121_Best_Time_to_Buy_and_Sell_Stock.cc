// https://leetcode-cn.com/leetbook/read/bytedance-c01/eib21s/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > ans(n, vector<int>(2, 0));

        ans[0][0] = 0;
        ans[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            ans[i][0] = max(ans[i-1][0], ans[i-1][1] + prices[i]);
            ans[i][1] = max(-prices[i], ans[i-1][1]);   
        } 

        return ans[n-1][0];
    }
};