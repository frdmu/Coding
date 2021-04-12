// https://leetcode-cn.com/problems/super-pow/
// solution: quick pow
class Solution {
public:
    int base = 1337; 
    int myPow(int x, int k) {
        if (k == 0)
            return 1;
        x %= base;
        if (k % 2 == 1) {
            return (x * myPow(x, k-1)) % base;
        } else {
            int y = myPow(x, k/2);
            return (y*y) % base;
        }
    }
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        int last = b.back();
        b.pop_back();

        int part1 = myPow(a, last);
        int part2 = myPow(superPow(a, b), 10);
        return (part1*part2)%base;
    }
};
