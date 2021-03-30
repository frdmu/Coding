// https://leetcode-cn.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int start = 0, end = height.size() - 1;
      	// move "start" and "end" to get larger area possibly. 
        while (start < end) {
            ans = max(ans, (end - start) * min(height[start], height[end])); 
            if (height[start] < height[end]) {
                start++;
            } else if (height[start] > height[end]) {
                end--;
            } else {
                start++;
                end--;
            }
        }

        return ans;
    }
};
