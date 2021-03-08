// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0, MaxArea = -1;
        int sz = heights.size();
        int i ; 
        for (i = 0; i < sz;) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                int index = st.top();
                st.pop();
                if (st.empty()) {
                    area = heights[index] * i;
                } else {
                    area = heights[index] * (i - st.top() - 1);
                }
                MaxArea = max(MaxArea, area);
            }
        }
        while (!st.empty()) {
            int index = st.top();
            st.pop();
            if (st.empty()) {
                area = heights[index] * i;
            } else {
                area = heights[index] * (i - st.top() - 1);
            }
            MaxArea = max(MaxArea, area);
        }

        return MaxArea;
    }
};  