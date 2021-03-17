// https://leetcode-cn.com/leetbook/read/bytedance-c01/eikfoc/
class Solution {
public:
    int factorial(int n) {
        if (n == 1 || n == 0) 
            return 1;
        return n * factorial(n - 1); 
    } 
	
    string getPermutation(int n, int k) {
        vector<bool> flag(n);
        vector<int> ans(n); 
        
        for (int i = 0; i < n; i++) {
            int tmp = factorial(n - 1 - i); 
            int group = (k%tmp ==0) ? k/tmp : k/tmp+1;
            '
			// group is a number
			// search group'th largest number among the unselected numbers through a hashtable
            int cnt = 0; 
            for (int j = 0; j < n; j++) {
                if (flag[j] == false) {
                    cnt++;
                } 
                if (cnt == group) {
                    ans[i] = j+1;
                    flag[j] = true;
                    break;
                }
            } 
			
            k = (k%tmp==0) ? tmp : k%tmp;
        }

        string str = "";
        for (auto item : ans) {
            str += to_string(item);
        }

        return str;
    }
};