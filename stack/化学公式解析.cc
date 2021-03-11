// https://leetcode-cn.com/leetbook/read/bytedance-c01/euzitj/
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string formula;
    cin >> formula;

    map<string, int> mp;
    stack<map<string, int> > stk;
    int n = formula.size();
    int i = 0;

    while (i < n) {
        char c = formula[i];
        if (formula[i] == '(' || formula[i] == '[') {
            stk.push(mp);
            mp.clear();
            i++;
        } else if (formula[i] == ')' || formula[i] == ']') {
            i++;
            int val = 0;
            while (i < n && isdigit(formula[i])) {
                val = val * 10 + formula[i] - '0';
                i++;
            }
            if (val == 0) 
                val = 1;

            map<string, int> tmp = mp;
            mp = stk.top();
            stk.pop();
            for (auto it = tmp.begin(); it != tmp.end(); it++) {
                mp[it->first] += it->second * val;
            }
        } else {
            int j = i;
            i++;
            while (i < n && islower(formula[i]))
                i++;
            string str = formula.substr(j, i-j);
            int val = 0;
            while (i < n && isdigit(formula[i])) {
                val = val * 10 + formula[i] - '0';
                i++;
            }
            if (val == 0) 
                val = 1;
            
            mp[str] += val;
        }
    }

    string res;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        res += (it->first + to_string(it->second));
    }
    cout << res << endl;
    
    return 0;
}