// https://leetcode-cn.com/problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int flag = 1; // default positive
        int index = 0; 
        long long ans = 0;
        int cnt = 0;

        while (s[index] == ' ')
            index++;
        if (s[index] == '+') {
            cnt++;
            index++;
        }
        if (s[index] == '-') { 
            cnt++; 
            flag = 2;
            index++;
        }
        if (cnt > 1) {
            return 0;
        }
        for (int i = index; i < size; i++) {
            if (!isdigit(s[i]))
                break; 
            if (flag == 2 && -(ans * 10) < INT_MIN)
                return INT_MIN;
            if (flag && ans * 10 > INT_MAX)
                return INT_MAX;
            ans = ans * 10 + s[i] - '0'; 
        }
        if (flag == 2)
            ans = -ans;
        if (ans < INT_MIN)
            return INT_MIN;
        if (ans > INT_MAX)
            return INT_MAX;
        return ans;        
    }
};