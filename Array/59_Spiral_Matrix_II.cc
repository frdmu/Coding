// https://leetcode-cn.com/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n));
        vector<vector<bool> > flag(n, vector<bool>(n));
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        int total = n * n;
        int index = 0;
        int i = 0, j = 0;
        
        for (int k = 1; k <= total; k++) {
            flag[i][j] = true;
            ans[i][j] = k;

            int nexti = i + direction[index][0], nextj = j + direction[index][1];
            if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= n || flag[nexti][nextj]) {
                index = (index + 1) % 4;
            }
            
            i += direction[index][0];
            j += direction[index][1]; 
        }

        return ans;
    }
};