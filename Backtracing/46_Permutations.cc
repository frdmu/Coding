// https://leetcode-cn.com/problems/permutations/
class Solution {
public:
    void permutation(vector<int> &tmp, vector<vector<int> >& ans, vector<int>& nums, vector<int> &visited) {
        int n = nums.size();
        if (tmp.size() == n) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                tmp.push_back(nums[i]);
                permutation(tmp, ans, nums, visited);
                tmp.pop_back();
                visited[i] = 0;
            }
        }
    
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int> > ans;
        
        int len = nums.size();
        if (len == 0) {
            return {};
        }
        vector<int> visited(len, 0); 
        
        permutation(tmp, ans, nums, visited);
        
        return ans;
    }
};
