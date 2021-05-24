// https://leetcode-cn.com/problems/palindrome-partitioning/
class Solution {
public:
    vector<string> path;
    vector<vector<string> > ans; 
    bool isPalindrome(string s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) 
                return false;
        }
        return true;
    }
    void backtracing(string s, int startIndex) {
        if (s.size() == startIndex) {
            ans.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                path.push_back(s.substr(startIndex, i-startIndex+1));
            } else {
                continue;
            }
            backtracing(s, i+1);
            path.pop_back();
        }
    } 
    vector<vector<string>> partition(string s) {
        backtracing(s, 0);
        return ans;
    }
};
