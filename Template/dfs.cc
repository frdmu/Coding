dfs(vector<int>& tmp, vector<vector<int>>& ans, vector<int> nums) {
	int n = nums.size();	
	if (tmp.size() == n) {
		ans.push_back(tmp);
		return;	
	}
	for (int i = 0; i < n; i++) {
		if (satisfy some conditions) {	
			tmp.push_back(nums[i]);
			dfs(tmp, ans, nums);
			tmp.pop_back();
		}
	}
}
