// https://leetcode-cn.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> record(26, 0);
        int n = s.size();
        
        if (n != t.size())
            return false; 
        
        for (int i = 0; i < n; i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0)
                return false;
        }
        
        return true;
    }
};
