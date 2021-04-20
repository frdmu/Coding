// https://leetcode-cn.com/problems/happy-number/
class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> tmpSet; 
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (tmpSet.find(sum) != tmpSet.end()) {
                return false;
            } else {
                tmpSet.insert(sum);
            }
            n = sum;
        }
    }
};
