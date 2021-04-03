// https://leetcode-cn.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int len = s.size();
        map<char, char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';

        for (int i = 0; i < len;) {
            char ch = s[i];
            
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
                i++;
            } else {
                if (!stk.empty() && stk.top() == mp[ch]) {
                    stk.pop();
                    i++;
                } else {
                    return false;
                }
            }
        }

        if (stk.empty()) {
           return true; 
        } else {
            return false;
        }
    }
};