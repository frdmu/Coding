# 动态规划总结

## 遍历方向

```c++
// 斜着遍历数组
for (int l = 2; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
        int j = l + i - 1;
        // 计算 dp[i][j]
    }
}
```

## dp数组的定义方法

### [一、子序列问题](https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E5%AD%90%E5%BA%8F%E5%88%97%E9%97%AE%E9%A2%98%E6%A8%A1%E6%9D%BF.md)
dp数组通常有两种定义方式，一维和二维，典型的例子如下所示：
```c++
1. 最长递增子序列dp[i]: 以nums[i]这个元素结尾的最长递增子序列的长度。
2. 最长回文子序列dp[i][j]: 子串s[i...j]的最长回文子序列长度。
```
### [二、打家劫舍问题](https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E6%8A%A2%E6%88%BF%E5%AD%90.md)
```c++
dp[i]表示从i开始抢劫，所能抢到的最多的钱。
dp[i] = max(dp[i+1], nums[i] + dp[i+2])

base case:
0 <= i < n
dp[n] = dp[n+1] = 0
```
### 三、背包问题
#### [0-1背包](https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98.md)
```c++
dp[i][w]: 前i个物品，放进容量是W的背包，可以装的最大价值。
dp[i][w] = max(dp[i-1][w], val[i]+dp[i-1][w-weight[i]])
0 <= i <= n, 0 <= w <= W
base case:
dp[0][...] = dp[...][0] = 0
```

### [四、股票买卖问题](https://github.com/labuladong/fuckingalgorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E5%9B%A2%E7%81%AD%E8%82%A1%E7%A5%A8%E9%97%AE%E9%A2%98.md)

- 数组定义：
```c++
dp[i][k][0 or 1]           0 <= i < n,  0 < k <= K
例如 dp[2][3][0]表示  第2天没有持有股票，至此最多进行3次交易的情况下的最大利润。
```
- 状态转移方程：

![1](https://user-images.githubusercontent.com/50523407/132189002-c1176727-1125-4270-a0e1-2127c3c8cfc9.png)

```c++
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);

base case:
dp[-1][k][0] = dp[i][0][0] = 0;
dp[-1][k][1] = dp[i][0][1] = -inf;
```
