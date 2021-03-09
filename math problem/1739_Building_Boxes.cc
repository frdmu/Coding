// https://leetcode-cn.com/leetbook/read/bytedance-c01/eikfoc/
class Solution {
public:
    int minimumBoxes(int n) {
        // 1. find level
        int sum = 0, level, levelSum;
        for (int i = 1; i <= n; i++) {
            levelSum = i * (i+1) / 2;
            sum += levelSum;
            if (sum >= n) {
                level = i;
                break;
            }
        }
        // 2.result
        int cnt = 1; 
        int sum0 = sum - levelSum; 
        int levelIndex = n - sum0;
        if (levelIndex == 0) return ((level-1)*level/2);
        while (levelIndex > 0) {
            levelIndex -= cnt;
            cnt++;
        }
        return ((level-1)*level/2 + cnt - 1);
    }
};