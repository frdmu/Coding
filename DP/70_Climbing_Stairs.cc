// https://leetcode-cn.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        int vec[50];
        vec[0] = 1;
        vec[1] = 1; 
        for (int i = 2; i <= n; i++) {
            vec[i] = vec[i-1] + vec[i-2];
        } 
        return  vec[n];
    }
};