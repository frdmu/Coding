// https://leetcode-cn.com/problems/restore-ip-addresses/
class Solution {
public:
    vector<string> ans;
    bool isValid(string s, int start, int end) {
        if (start > end) return false;
        if (s[start] == '0' && start != end) return false; 
        int num = 0; 
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0')
                return false;
            num = num * 10 + (s[i] - '0');
        }
        if (num > 255) 
            return false;
        return true;
    }
    void backtracing(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (isValid(s, startIndex, s.size()-1)) {
                ans.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin()+i+1, '.');
                backtracing(s, i+2, pointNum+1);
                s.erase(s.begin()+i+1);
            } else {
                break;
            }
        }
    } 
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return {}; 
        backtracing(s, 0, 0);
        return ans;
    }
};
