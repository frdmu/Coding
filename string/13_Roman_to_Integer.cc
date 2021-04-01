// https://leetcode-cn.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['V'] = 5;
        mp['L'] = 50;
        mp['D'] = 500;
        mp['M'] = 1000;
        int len = s.size();
        int res = 0;
        
        for (int i = 0; i < len; i++) {
            char ch = s[i];
            if (ch == 'I') {
                if (s[i+1] == 'V') {
                    res += 4;
                    i++;
                    continue;
                }
                if (s[i+1] == 'X') {
                    res += 9;
                    i++;
                    continue;       
                }
                res += 1;
            } else if (ch == 'X') {
                if (s[i+1] == 'L') {
                    res += 40;
                    i++;
                    continue;
                }
                if (s[i+1] == 'C') {
                    res += 90;
                    i++;
                    continue;       
                }
                res += 10;
            } else if (ch == 'C') {
                if (s[i+1] == 'D') {
                    res += 400;
                    i++;
                    continue;
                }
                if (s[i+1] == 'M') {
                    res += 900;
                    i++;
                    continue;       
                }
                res += 100;
            } else {
                res += mp[ch];
            }
        }

        return res;
    }
};
// solution 2
// hashtable -> switch
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int len = s.size();

        for (int i = 0; i < len-1; i++) {
            int curVal = hash(s[i]);
            int nextVal = hash(s[i+1]);
            if (curVal >= nextVal) {
                ans += curVal;
            } else {
                ans -= curVal;
            }
        }
        ans += hash(s[len-1]);

        return ans;
    }
    int hash(char ch) {
        switch(ch) {
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
        }
        return 0;
    }
};
