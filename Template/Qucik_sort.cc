
// ===============双指针分区算法=======================
void quickSort(int arr[], int l, int h) {
	if (l >= h)
		return;
	
	// pivot is arr[l]
	int i = l, j = h;
	while (i < j) {
		while (i < j && arr[j] > arr[l]) j--;
		while (i < j && arr[i] <= arr[l]) i++;	
		swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[i]);

	quickSort(arr, l, i-1);
	quickSort(arr, i+1, h);
}


// 优化版本：随机选取基准
#include <cstdlib> // rand() 头文件
void quickSort(int arr[], int l, int h) {
	if (l >= h)
		return;
	
	// pivot is arr[l]
	int i = l, j = h;
	int p = rand() % (h - l + 1) + l;
	swap(arr[l], arr[p]);
	while (i < j) {
		while (i < j && arr[j] > arr[l]) j--;
		while (i < j && arr[i] <= arr[l]) i++;	
		swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[i]);

	quickSort(arr, l, i-1);
	quickSort(arr, i+1, h);
}
