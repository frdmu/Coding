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
