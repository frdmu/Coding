// https://leetcode-cn.com/problems/reverse-words-in-a-string
class Solution {
public:
    void removeExtraSpace(string &s) {
        int lowIndex = 0, fastIndex = 0;
        int n = s.size(); 
        
        while (fastIndex < n && s[fastIndex] == ' ') fastIndex++;
        while (fastIndex < n) {
            if (s[fastIndex] != ' ') {
                s[lowIndex++] = s[fastIndex++];
                continue;
            } else if (fastIndex < n-1 && s[fastIndex+1] != ' ') {
                    s[lowIndex++] = ' ';
            }
            fastIndex++;
        }
        s.resize(lowIndex);
    }
    void reverse(string &s, int low, int high) {
        for (int i = low, j = high-1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseWords(string s) {
        removeExtraSpace(s);
        int n = s.length();
        reverse(s, 0, n);
        int lowIndex = 0, fastIndex = 0;
        
        while (fastIndex < n) {
            while (fastIndex <n && s[fastIndex] != ' ') fastIndex++;
            reverse(s, lowIndex, fastIndex);
            fastIndex++;
            lowIndex = fastIndex;
        }
        return s;
    }
}
