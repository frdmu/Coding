// https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0, n = nums.size();
        for (int i = 0; i < k; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i]; 
            } else {
                int t = k - i;
                if (t%2 == 1) {
                    if (i > 0) {
                        if (nums[i] > nums[i-1]) 
                            nums[i-1] = -nums[i-1];
                        else
                            nums[i] = -nums[i];
                    } else {
                        nums[i] = -nums[i];
                    }
                }
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return sum;
    }
};
