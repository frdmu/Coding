// https://leetcode-cn.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> tmp_set(nums1.begin(), nums1.end());

        for (int num : nums2) {
            if (tmp_set.find(num) != tmp_set.end()) {
                result_set.insert(num);
            }
        }

        return vector<int>(result_set.begin(), result_set.end());
    }
};
