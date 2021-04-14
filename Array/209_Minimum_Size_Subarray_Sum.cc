// https://leetcode-cn.com/problems/minimum-size-subarray-sum/
// solution: sliceing window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    /*  int n = nums.size();
        int sum, len;
        int result = INT_MAX; 
        
        for (int i = 0; i < n; i++) {
            sum = 0; 
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= target) {
                    len = j - i + 1;
                    result = min(result, len);
                    break;
                }
            }
        }

        return result == INT_MAX ? 0 : result; 
    */
        int n = nums.size();
        int sum = 0, len;
        int result = INT_MAX;
        int i = 0;
        
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            while (sum >= target) {
                len = j - i + 1;
                result = min(result, len);
                sum -= nums[i++];
            }
        } 

        return result == INT_MAX ? 0 : result;
    }
};
