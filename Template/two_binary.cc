// ordered array
two_binary(int arr[]) {
	int n = arr.size();
	int low = 0, high = n-1;
->	while (low < high) {
		int mid = low + (high - low) / 2;	
		if (arr[mid] > arr[high]) {
			do something;		
		} else {
			do something;	
		}
	}	
}
