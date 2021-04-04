// https://leetcode-cn.com/leetbook/read/sort-algorithms/etdd3m/
// solution: recursive template
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int len = nums.size(); 
        vector<int> vec(len); 
        return mergeSortCount(nums, 0, len-1, vec);
    }
    int mergeSortCount(vector<int>& nums, int start, int end, vector<int>& vec) {
        if (start < end) {
            int mid = (start + end) / 2;
            int left = mergeSortCount(nums, start, mid, vec);
            int right = mergeSortCount(nums, mid+1, end, vec);
            int cnt = mergeCount(nums, start, mid, mid+1, end, vec);
            return left + right + cnt; 
        }
        return 0;
    }
    int mergeCount(vector<int> &nums, int start1, int end1, int start2, int end2, vector<int>& vec) {
        int ans = 0;
        int index = start1;
        int start = start1;
        
        while(start1 <= end1 && start2 <= end2) {
            if (nums[start1] > nums[start2]) {
                vec[index++] = nums[start2++];
                ans += end1 - start1 + 1; 
            } else {
                vec[index++] = nums[start1++];
            }
       } 
       while(start1 <= end1) {
           vec[index++] = nums[start1++];
       }
       while(start2 <= end2) {
           vec[index++] = nums[start2++];
       }
       while (start < index) {
           nums[start] = vec[start];
           start++;
       }
       
       return ans;
    }
};
