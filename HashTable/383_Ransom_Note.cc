// https://leetcode-cn.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        int m = magazine.length();
        int n = ransomNote.length();
        
        for (int i = 0; i < m; i++) {
            record[magazine[i] - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            record[ransomNote[i] - 'a']--;
            if (record[ransomNote[i] - 'a'] < 0)
                return false;
        }

        return true;
    }
};
