// https://leetcode-cn.com/problems/sudoku-solver/
class Solution {
public:
    bool isValid(vector<vector<char> >& board, int row, int col, int k) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == k)
                return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == k)
                return false;
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow+3; i++) {
            for (int j = startCol; j < startCol+3; j++) {
                if (board[i][j] == k)
                    return false;
            }
        }
        return true;
    }
    bool backtracing(vector<vector<char> >& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') continue; 
                for (int k = '1'; k <= '9'; k++) {
                    if (isValid(board, row, col, k)) {
                        board[row][col] = k;
                        if (backtracing(board)) return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }   
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracing(board);
    }
};
