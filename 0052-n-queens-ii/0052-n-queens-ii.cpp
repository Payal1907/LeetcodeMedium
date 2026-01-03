class Solution {
public:
    bool canPlaceQueen(int row, int col, vector<string> board, int n) {
        int duplicateRow = row;
        int duplicateCol = col;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        row = duplicateRow;
        col = duplicateCol;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }
        row = duplicateRow;
        col = duplicateCol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (canPlaceQueen(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> ans;
        string eachRow(n, '.');
        vector<string> board(n); // must be of size n, can lead to runtime error
        for (int i = 0; i < n; i++) {
            board[i] = eachRow;
        }
        solve(0, board, ans, n);
        return ans.size();
    }
};
