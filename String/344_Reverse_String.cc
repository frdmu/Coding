// https://leetcode-cn.com/problems/reverse-string/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        if (n == 1)
            return;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            swap(s[left], s[right]); 
            left++;
            right--;
        }
    }
};