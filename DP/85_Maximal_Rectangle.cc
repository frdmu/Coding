// https://leetcode-cn.com/leetbook/read/bytedance-c01/eik5p2/
class Solution {
public:
    int largestRectangleArea(vector<int> heights) {
        stack<int> st;
        int sz = heights.size();
        int MaxArea = -1, area;
        int i; 
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
	
    int maximalRectangle(vector<vector<char>>& matrix) {
        int MaxArea = -1, area;
        int row = matrix.size();
        if (!row) return 0;
        int col = matrix[0].size();
        vector<int> tmp(col, 0);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') {
                    tmp[j] = 0;
                } else {
                    tmp[j]++;
                }
            }
            area = largestRectangleArea(tmp);
            MaxArea = max(MaxArea, area); 
        }

        return MaxArea;
    }
};