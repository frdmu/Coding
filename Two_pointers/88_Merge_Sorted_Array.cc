// https://leetcode-cn.com/problems/merge-sorted-array/
/*
// #1 merge and sort
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[i+m] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};
*/

/*
// #2 two pointer
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        for(int i = 0; i < m; i++) {
            tmp.push_back(nums1[i]);
        }

        int i = 0, j = 0, cnt = 0;
        while (i != m && j != n) {
            if (tmp[i] < nums2[j]) {
                nums1[cnt++] = tmp[i++];
            } else {
                nums1[cnt++] = nums2[j++];
            }
        }
        while(i != m) {
            nums1[cnt++] = tmp[i++];
        }
        while(j != n) {
            nums1[cnt++] = nums2[j++];
        }
    }
};
*/
// #3 two pointer, from end to start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        m = m -1;
        n = n - 1;
        while (m >= 0 || n >= 0) {
            if (m < 0) {
                nums1[index--] = nums2[n--];
            } else if (n < 0) {
                nums1[index--] = nums1[m--];
            } else if (nums1[m] > nums2[n]) {
                nums1[index--] = nums1[m--];
            } else if (nums1[m] <= nums2[n]){
                nums1[index--] = nums2[n--];
            } 
        }
    }
};
