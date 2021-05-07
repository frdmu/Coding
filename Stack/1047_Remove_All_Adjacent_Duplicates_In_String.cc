// https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        string ans;
        
        for (auto ch : S) {
            if (!stk.empty() && stk.top() == ch) {
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};


class Solution {
public:
    string removeDuplicates(string S) {
        string ans;

        for (auto ch : S) {
            if (!ans.empty() && ans.back() == ch) {
                ans.pop_back();
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};
