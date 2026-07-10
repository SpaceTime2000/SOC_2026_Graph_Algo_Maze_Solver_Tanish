// 130. Surrounded Regions
// Approach: Any 'O' connected to the border can never be surrounded. Run DFS
// from every border 'O', marking safe cells with a temporary marker '#'.
// Afterwards flip remaining 'O' -> 'X' and restore '#' -> 'O'.
// Time: O(m*n)  Space: O(m*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            markSafe(board, i, 0, m, n);
            markSafe(board, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++) {
            markSafe(board, 0, j, m, n);
            markSafe(board, m - 1, j, m, n);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

private:
    void markSafe(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        board[i][j] = '#';
        markSafe(board, i + 1, j, m, n);
        markSafe(board, i - 1, j, m, n);
        markSafe(board, i, j + 1, m, n);
        markSafe(board, i, j - 1, m, n);
    }
};

int main() {
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    Solution sol;
    sol.solve(board);
    for (auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }
    return 0;
}
