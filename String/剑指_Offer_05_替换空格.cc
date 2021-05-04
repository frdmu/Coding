// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
// solution: resize and operate from end to begin
class Solution {
public:
    string replaceSpace(string s) {
        int m = s.size();
        int cnt = 0;
       
        for (int i = 0; i < m; i++) {
            if (s[i] == ' ')
                cnt++; 
        }
        s.resize(m + 2*cnt);
        int n = s.size();
        for (int i = n-1, j = m-1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i-1] = '2';
                s[i-2] = '%';
                i -= 2;
            }
        }

        return s;
    }
};
