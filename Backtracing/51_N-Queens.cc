// https://leetcode-cn.com/problems/n-queens/
class Solution {
public:
    vector<vector<string> > ans;
    bool isValid(int n, int row, int col, vector<string>& chessboard) {
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q')
                return false;
        }
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void backtracing(int n, int row, vector<string>& chessboard) {
        if (row == n) {
            ans.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(n, row, col, chessboard)) {
                chessboard[row][col] = 'Q';
                backtracing(n, row+1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    } 
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.')); 
        backtracing(n, 0, chessboard);
        return ans;
    }
};
