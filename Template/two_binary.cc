// ordered array
two_binary(int arr[], int target) {
	int n = arr.size();
	int low = 0, high = n-1;
->	while (low <= high) {
		int mid = low + (high - low) / 2;	
		if (arr[mid] > target) {
			do something;		
		} else {
			do something;	
		}
	}	
}


++++++++++++++++++++++++二分查找小结++++++++++++++++++++++++++++
摘自:https://www.cnblogs.com/grandyang/p/6854825.html

第一类.当查找和目标值完全相等的数

int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return -1;
}

注意二分查找法的写法并不唯一，主要可以变动地方有四处： 
第一处是 right 的初始化，可以写成 nums.size() 或者 nums.size() - 1。
第二处是 left 和 right 的关系，可以写成 left < right 或者 left <= right。
第三处是更新 right 的赋值，可以写成 right = mid 或者 right = mid - 1。
第四处是最后返回值，可以返回 left，right，或 right - 1。 

但是这些不同的写法并不能随机的组合，正确的组合方式为下面两种：
right = nums.size(), left < right, right = mid
right = nums.size()-1, left <= right, right = mid - 1



第二类.查找第一个不小于目标值的数，可变形为查找最后一个小于目标值的数

这是比较常见的一类，因为我们要查找的目标值不一定会在数组中出现，也有可能是跟目标值相等的数在数组中并不唯一，而是有多个，那么这种情况下 nums[mid] == target 这条判断语句就没有必要存在。比如在数组 [2, 4, 5, 6, 9] 中查找数字3，就会返回数字4的位置；在数组 [0, 1, 1, 1, 1] 中查找数字1，就会返回第一个数字1的位置。我们可以使用如下代码：

int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return right;
}

这一类可以轻松的变形为查找最后一个小于目标值的数，怎么变呢。我们已经找到了第一个不小于目标值的数，那么再往前退一位，返回 right - 1，就是最后一个小于目标值的数。


第三类： 查找第一个大于目标值的数，可变形为查找最后一个不大于目标值的数

只需要添加一个等号，将之前的 nums[mid] < target 变成 nums[mid] <= target。代码如下：

int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return right;
}

这一类可以轻松的变形为查找最后一个不大于目标值的数，怎么变呢。我们已经找到了第一个大于目标值的数，那么再往前退一位，返回 right - 1。

第四类： 用子函数当作判断关系（通常由 mid 计算得出）
暂时不管

第五类： 其他（通常 target 值不固定）
暂时不管


