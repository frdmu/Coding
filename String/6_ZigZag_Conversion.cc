// https://leetcode-cn.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (len <= numRows || numRows == 1) {
            return s;
        }
        int base = 2 * (numRows - 1);
        string ans = "";

        for (int i = 0; i < numRows; i++) {
            ans += s[i];
            int j = i;
            while (j + base - 2*i< len) {
                if (i > 0 && i < numRows-1) {
                    ans += s[j + base - 2*i];   
                }
                if (j + base < len) {
                    ans += s[j + base];      
                }
                j += base;
            }
        }

        return ans;
    }
};
