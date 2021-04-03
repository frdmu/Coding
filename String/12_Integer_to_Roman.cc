// https://leetcode-cn.com/problems/integer-to-roman/
class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        int nums[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string str[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        
	while (num) {
            for (int i = 0; i < 13; i++) {
                if (num < nums[i]) {
                    num -= nums[i-1];
                    s += str[i-1]; 
                    break; 
                }
                if (num == nums[i]) {
                    num -= nums[i];
                    s += str[i];
                    break;
                }
                if (num >= nums[12]) {
                    num -= nums[12];
                    s += str[12];
                    break;
                }
            }
        }

        return s;
    }
};
