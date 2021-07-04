// https://leetcode-cn.com/problems/set-mismatch/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n, 0);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            hash[nums[i]-1]++;
            if (hash[nums[i]-1] == 2)
                res.push_back(nums[i]); 
        }        
        for (int i = 0; i < n; i++) {
            if (hash[i] == 0) {
                res.push_back(i+1); 
                break;
            }
        }

        return res;
    }
};
