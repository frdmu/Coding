## Problem List (163)
### Leet Code
| # | Title | Solution | Difficulty |
|---| ----- | -------- | ---------- |
|1846|[Maximum Element After Decreasing and Rearranging](https://github.com/frdmu/LeetCode/issues/15)|```Array``` ```Sort```|Medium|
|1818|[Minimum Absolute Sum Difference](https://github.com/frdmu/LeetCode/issues/14)|```Array``` ```Binary Search```|Medium|
|981|[Time Based Key-Value Store](https://github.com/frdmu/LeetCode/issues/7)|```Hash Table```|Medium|
|930|[Binary Subarrays With Sum](https://github.com/frdmu/LeetCode/issues/2)|```Prefix Sum``` ```Hash Table```|Medium|
|560|[Subarray Sum Equals K](https://github.com/frdmu/LeetCode/issues/1)|```Prefix Sum``` ```Hash Table```|Medium|
|475|[Heaters](https://github.com/frdmu/LeetCode/issues/10)|```Array``` ```Binary Search```|Medium|
|406|[Queue Reconstruction by Height](https://github.com/frdmu/LeetCode/issues/8)|```Greedy``` ```Sort & Insert```|Medium|
|378|[Kth Smallest Element in a Sorted Matrix](https://github.com/frdmu/LeetCode/issues/11)|```Heap```|Medium|
|349|[Intersection of Two Arrays](https://github.com/frdmu/LeetCode/issues/9)|```Hash Table``` ```Binary Search```|Simple|
|275|[H-Index II](https://github.com/frdmu/LeetCode/issues/12)|```Binary Search```|Medium|
|274|[H-Index](https://github.com/frdmu/LeetCode/issues/6)|```Sort``` ```Simulation```|Medium|
|229|[Majority Element II](https://github.com/frdmu/LeetCode/issues/16)|```Moore Vote```|Medium|
|218|[The Skyline Problem](https://github.com/frdmu/LeetCode/issues/13)|```Heap``` ```Line Sweep```|Hard|

### 剑指 Offer 
| # | Title | Solution | Difficulty |
|---| ----- | -------- | ---------- |
|37|[序列化二叉树](https://github.com/frdmu/LeetCode/issues/3)|```Level Order``` ```Simulation```|Hard|
|09|[用两个栈实现队列](https://github.com/frdmu/LeetCode/issues/5)|```Simulation```|Simple|
### 面试题
| # | Title | Solution | Difficulty |
|---| ----- | -------- | ---------- |
|17.10|[主要元素](https://github.com/frdmu/LeetCode/issues/4)|```Moore Vote```|Simple| 

### Class
| # | Type | Quantity |Feature|
|---|---|---|---|
|1| [Array](https://github.com/frdmu/LeetCode/tree/master/Array) | 9 |binary search, slicing window, fast and slow pointer, simulate|
|2| [Backtracing](https://github.com/frdmu/LeetCode/tree/master/Backtracing) | 17 || 
|3| [Design](https://github.com/frdmu/LeetCode/tree/master/Design) | 3 ||
|4| [Dfs_Bfs](https://github.com/frdmu/LeetCode/tree/master/Dfs_Bfs) | 1 ||
|5| [Divide_and_Conquer](https://github.com/frdmu/LeetCode/tree/master/Divide_and_Conquer) | 2 | |
|6| [DP](https://github.com/frdmu/LeetCode/tree/master/DP) | 10 | |
|7| [Greedy_algorithm](https://github.com/frdmu/LeetCode/tree/master/Greedy_algorithm)| 11 ||
|8| [HashTable](https://github.com/frdmu/LeetCode/tree/master/HashTable)| 8 ||
|9| [Heap](https://github.com/frdmu/LeetCode/tree/master/heap) | 2 ||
|10| [List](https://github.com/frdmu/LeetCode/tree/master/List)| 8 |new a dummy head node|
|11| [Math](https://github.com/frdmu/LeetCode/tree/master/Math) | 8| |
|12| [Search](https://github.com/frdmu/LeetCode/tree/master/Search) | 4| |
|13| [Sort](https://github.com/frdmu/LeetCode/tree/master/Sort) | 3| |
|14|[Stack](https://github.com/frdmu/LeetCode/tree/master/Stack)|8||
|15|[String](https://github.com/frdmu/LeetCode/tree/master/String)| 10 ||
|16| [Tree](https://github.com/frdmu/LeetCode/tree/master/Tree) | 31 ||
|17|[Two pointers](https://github.com/frdmu/LeetCode/tree/master/Two_pointers)|11|sorted array, fast and slow pointer|
|18|[Nowcoder](https://github.com/frdmu/LeetCode/tree/master/Nowcoder)| 1 ||
## Notes
###  Useful Functions
|STL| Func | Description | Lib |
| ----- | ----- | ----- | ------ |
|string|int isdigit(char ch)|isdigit('2')| \<cstdio\> |
|string|string substr(int pos, int len)|s.substr(0, 5))|\<string\>|
|string|void resize(int n)|s.resize(n))|\<string\>|
|string|int stoi("22")|string to int|\<string\>|
|string|empty(), back(), push_back(), pop_back()|just like a stack|\<string\>|
|map|insert(x)|element traversal only via the iterator:\*it|\<map\>|
|map|iterator find(key)|mp.find(key)|\<map\>|
|vector|vec.push_back(vector\<int\>{1, 2, 3})|vector\<vector\<int\> \> vec|\<vector\>|
|vector|vec.assign(a.begin(), a.begin()+k)|copy data from a to vec|\<vector\>|
|vector|vec.emplace_back(ele)|similar to push_back(ele)|\<vector\>|
|-|reverse(vec.begin(), vec.end())|-|\<algorithm\>|
|unordered_set|insert(), find()|unordered_set<int> tmp(vec.begin(), vec.end())|\<unordered_set\>|

### Useful template
- [Divide&conquer: Merge_sort, Qucik_sort](https://github.com/frdmu/LeetCode/tree/master/Template)
- [Backtracing: dfs, Backtracing](https://github.com/frdmu/LeetCode/tree/master/Template)
- [Search: two_binary](https://github.com/frdmu/LeetCode/tree/master/Template)
- [Tree: traversa, pathl](https://github.com/frdmu/LeetCode/tree/master/Template)

### Hard understand
|Problem|
|--|
|[31.Next Permutation(Array)](https://leetcode-cn.com/problems/next-permutation/)|
|[264.Ugly Number II(DP)](https://leetcode-cn.com/problems/ugly-number-ii/)| 
|[347.Top K Frequent Elements(Heap)](https://leetcode-cn.com/problems/top-k-frequent-elements/)|
|[239. Sliding Window Maximum(Monotonous queue)](https://leetcode-cn.com/problems/sliding-window-maximum/)|

## Refer
- https://github.com/youngyangyang04/leetcode-master
- https://github.com/grandyang/leetcode
- https://github.com/labuladong/fucking-algorithm

