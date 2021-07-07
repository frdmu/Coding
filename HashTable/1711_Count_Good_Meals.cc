// https://leetcode-cn.com/problems/count-good-meals/:
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int mod = 1e9 + 7; 
        map<int, int> mp;
        int res = 0;
        for (auto e : deliciousness) {
            for (int i = 0; i < 22; i++) {
                int target = (1<<i) - e;
                res = (res + mp[target]) % mod;
            }
            mp[e]++;
        }
        return res;
    }
};
