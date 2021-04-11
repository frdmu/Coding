// https://leetcode-cn.com/problems/ugly-number-ii/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        
        for (int i = 2; i <= n; i++) {
            int num = min(min(dp[p2]*2, dp[p3]*3), dp[p5]*5);
            dp[i] = num;
            if (num == dp[p2] * 2) {
                p2++;
            } 
            if (num == dp[p3] * 3) {
                p3++;
            } 
            if (num == dp[p5] * 5){
                p5++;
            }
        }        

        return dp[n];
    }
};
