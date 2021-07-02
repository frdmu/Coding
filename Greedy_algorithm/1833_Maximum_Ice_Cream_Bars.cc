// https://leetcode-cn.com/problems/maximum-ice-cream-bars/
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int sum = 0, res = 0, n = costs.size(); 
        sort(costs.begin(), costs.end());
        for (int i = 0; i < n; i++) {
            sum += costs[i];
            res++;
            if (sum == coins) 
                break;
            if (sum > coins) {
                res--; 
                break;
            }
        }

        return res;
    }
};
