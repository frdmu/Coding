// https://leetcode-cn.com/leetbook/read/bytedance-c01/oh7oa1/
class Solution {
public:
    void generate(string str, vector<string> &ans, string &digits, map<char, string> &mp, int index) {
        int n = digits.size(); 
        if (index == n) {
            ans.push_back(str);
        } else {
            char ch = digits[index];
            string tmpstr = mp[ch];
            for (auto c : tmpstr) {
                generate(str+c, ans, digits, mp, index+1);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string str = ""; 
        map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs"; 
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        int n = digits.size(); 
        if (n == 0) {
            return ans;
        } 
        generate(str, ans, digits, mp, 0);
        return ans;
    }
};