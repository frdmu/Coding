// https://leetcode-cn.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
        int row = matrix.size(), column = matrix[0].size();
        vector<vector<bool> > visited(row, vector<bool>(column));        
        int total = row * column;
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        
        int currow = 0, curcolumn = 0;
        int index = 0; // direction index
        for (int i = 0; i < total; i++) {
            visited[currow][curcolumn] = true;
            res.push_back(matrix[currow][curcolumn]);
            
            // test wheather should update direction 
            int nextrow = currow + direction[index][0], nextcolumn = curcolumn + direction[index][1];
            if (nextrow < 0 || nextrow >= row || nextcolumn < 0 || nextcolumn >= column || visited[nextrow][nextcolumn]) {
                index = (index + 1) % 4; 
            }
            // update currow & curcolumn 
            currow += direction[index][0];
            curcolumn += direction[index][1];
        } 

        return res;
    }
};