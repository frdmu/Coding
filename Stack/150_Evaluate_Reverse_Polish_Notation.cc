// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for (auto ch : tokens) {
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                if (ch == "+") stk.push(op1 + op2);
                if (ch == "-") stk.push(op1 - op2);
                if (ch == "*") stk.push(op1 * op2);
                if (ch == "/") stk.push(op1 / op2);
            } else {
                stk.push(stoi(ch));
            }    
        }

        return stk.top();
    }
};
