// https://leetcode-cn.com/problems/powx-n/
// solution: recursive
class Solution {
public:
    double myFunc(double x, long long n) {
        if (n == 0)
            return 1.0;
        double y = myFunc(x, n/2);
        return n%2==0 ? y*y : y*y*x;
    }
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? myFunc(x, N) : 1.0 / myFunc(x, -N);
    }
};
