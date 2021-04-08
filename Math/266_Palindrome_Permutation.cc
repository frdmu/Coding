// https://leetcode-cn.com/problems/palindrome-permutation/
// solution: hashtable
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int cnt = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second % 2 == 1) {
                cnt++;
                if (cnt > 1) 
                    return false; 
            }
        }

        return true;
    }
};
