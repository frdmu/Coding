// https://leetcode-cn.com/problems/longest-palindrome/
// solution: hashtable
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second % 2 == 1) 
                cnt++;
        }
        return cnt > 1 ? n - (cnt-1): n; 
    }
};
