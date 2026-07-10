// 542. 01 Matrix
// Approach: Multi-source BFS starting from every 0 cell simultaneously,
// expanding outward so the first time a 1-cell is reached gives its shortest
// distance to any 0.
// Time: O(m*n)  Space: O(m*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return dist;
    }
};

int main() {
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    Solution sol;
    auto result = sol.updateMatrix(mat);
    for (auto& row : result) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }
    return 0;
}
