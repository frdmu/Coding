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
// There are three cases that return false:
// case 1: There are more parenthesis on the left such as ([]{}
// case 2: There are more parenthesis on the right such as []{}}
// case 3: The number of parentheses meets the criteria, but does not match such as ([)]
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for (auto ch : s) {
            if (ch == '(') stk.push(')');
            else if (ch == '[') stk.push(']');
            else if (ch == '{') stk.push('}');
            // case 2 and case 3
            else if (stk.empty() || stk.top() != ch) return false;
            else stk.pop();
        }

        // case 1
        return stk.empty();
    }
};
