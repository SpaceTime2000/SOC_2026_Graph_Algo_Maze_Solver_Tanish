// N-Queens

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n,'.'));
        set<int> cols, d1, d2;
        function<void(int)> bt = [&](int row) {
            if (row == n) { res.push_back(board); return; }
            for (int col = 0; col < n; col++) {
                if (cols.count(col)||d1.count(row-col)||d2.count(row+col)) continue;
                board[row][col] = 'Q';
                cols.insert(col); d1.insert(row-col); d2.insert(row+col);
                bt(row+1);
                board[row][col] = '.';
                cols.erase(col); d1.erase(row-col); d2.erase(row+col);
            }
        };
        bt(0);
        return res;
    }
};

====================================================
