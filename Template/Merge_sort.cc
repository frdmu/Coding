//
// recursive version
//
void mergeSort(int nums[], int start, int end) {
->	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(nums, start, mid);
		mergeSort(nums, mid+1, end);
		merge(nums, start, mid, mid+1, end);		
	}
}
// merge two ordered sequences
void merge(int nums[], int start1, int end1, int start2, int end2) {
	int tmp[end2-start1+1];	
	int index = start1;
	int start = start1;	
->	while (start1 <= end1 && start2 <= end2) {
		if (nums[start1] > nums[start2]) {
			tmp[index++] = nums[start2++];	
		} else {
			tmp[index++] = nums[start1++];	
		}	
	}
->	while (start1 <= end1) {
		tmp[index++] = nums[start1++];	
	}
->	while (start2 <= end2) {
		tmp[index++] = nums[start2++];	
	}
	while (start < index) {
		nums[start] = tmp[start];
		start++;	
	}
}
