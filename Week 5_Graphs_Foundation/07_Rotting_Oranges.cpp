// 994. Rotting Oranges
// Approach: Multi-source BFS starting from all initially rotten oranges,
// spreading rot minute by minute. Track fresh count to detect impossibility.
// Time: O(m*n)  Space: O(m*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        int minutes = 0;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int size = q.size();
            bool rottedThisRound = false;
            for (int k = 0; k < size; k++) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        rottedThisRound = true;
                        q.push({nr, nc});
                    }
                }
            }
            if (rottedThisRound) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution sol;
    cout << "Minutes: " << sol.orangesRotting(grid) << endl;
    return 0;
}
