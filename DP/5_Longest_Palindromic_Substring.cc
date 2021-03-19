// https://leetcode-cn.com/leetbook/read/bytedance-c01/eijp4d/
class Solution {
public:
    string longestPalindrome(string s) {
        //dp[i][j]: str[i~j] is a palindromic substring 
        string ans;
        int size = s.size();
        vector<vector<int> > dp(size, vector<int>(size));
        int sub_left = 0, sub_right = 0, sub_len = 0;
        
        for (int j = 0; j < size; j++) {
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j]) {
                    if (i == j || j-i == 1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if (dp[i][j] && sub_len < j-i+1) {
                        sub_len = j-i+1;
                        sub_left = i;
                        sub_right = j;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        ans = s.substr(sub_left, sub_right-sub_left+1);
        return ans;
    }
};