# 滑动窗口答题框架

最重要的是窗口左移的部分。

```c++
int n = nums.size();
int left = 0, sum = 0;

for (int right = 0; right < n; right++) {
   sum += nums[right];
   res = .. 
   while (sum > k) {
        sum -= nums[left];
        left++;
   }
}

return res;
```
