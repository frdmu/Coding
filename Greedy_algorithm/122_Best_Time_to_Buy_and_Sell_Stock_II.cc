// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        int res = 0; 
        for (int i = 1; i < n; i++) {
            res += max(prices[i] - prices[i-1], 0);
        }

        return res;
    }
};
