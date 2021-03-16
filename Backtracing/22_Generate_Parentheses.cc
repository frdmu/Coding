// https://leetcode-cn.com/leetbook/read/bytedance-c01/eisgxg/
class Solution {
public:
    void generate(string str, vector<string> &ans, int n, int left, int right) {
        if (right == n) {
            ans.push_back(str);
        }
        if (left < n) {
            generate(str+"(", ans, n, left+1, right);
        }
        if (right < left) {
            generate(str+")", ans, n, left, right+1);
        }
    }

    vector<string> generateParenthesis(int n) { 
        vector<string> ans;
        generate("", ans, n, 0, 0);
        return ans;
    }
};