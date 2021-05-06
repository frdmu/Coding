// https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
// Solution: local reverse and global reverse
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin()+n);
        reverse(s.begin()+n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
