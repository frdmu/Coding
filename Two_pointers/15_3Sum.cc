// https://leetcode-cn.com/problems/3sum/

// use set avoid duplication
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        set<vector<int>>  ans;

        int len = nums.size();
        if (len < 3)
            return {};

        sort(nums.begin(), nums.end());
        for (int i = 0; i < len -2; i++) {
            int k = len - 1;
            int j = i + 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.insert({nums[i], nums[j++], nums[k--]});
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        for (auto item : ans) {
            res.push_back(item);
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans; 
        int len = nums.size();
        if (len < 3) return {};
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len-2; i++) {
            int left = i + 1;
            int right = len - 1;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    right--;
                    left++;
                }
            }
        }

        return ans;
    }
};
