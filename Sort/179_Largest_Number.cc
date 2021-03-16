// https://leetcode-cn.com/problems/largest-number/
class Solution {
public:
    static bool cmp(string a, string b) {
        string x = a + b;
        string y = b + a;
        if (x > y) // >= can't pass 
            return true;
        else
            return false;
    }
    string largestNumber(vector<int>& nums) {
        string str = "";
        vector<string> vec;
        
        for(auto item : nums) {
           vec.push_back(to_string(item)); 
        }
        sort(vec.begin(), vec.end(), cmp);
        for(auto item : vec) {
            str += item;
        }
        if (str[0] == '0') 
            return "0";
        
        return str;
    }
};