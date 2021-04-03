// https://leetcode-cn.com/problems/palindrome-number/

// 1.双指针太耗时间和空间
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        vector<int> vec;
        int len = 0; 
        while (x != 0) {
            vec.push_back(x % 10);
            len++;
            x /= 10;
        }
        for (int i = 0, j = len-1; i <= j; i++, j--) {
            if (vec[i] != vec[j])
                return false;
        }
        return true;

    }
};



// 2.求其一半长度的翻转数
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int reverseNumber = 0;
        while (x > reverseNumber) {
            reverseNumber = reverseNumber * 10 + x % 10;
            x /= 10;
        }
        return x == reverseNumber || x == reverseNumber / 10;
    }
};