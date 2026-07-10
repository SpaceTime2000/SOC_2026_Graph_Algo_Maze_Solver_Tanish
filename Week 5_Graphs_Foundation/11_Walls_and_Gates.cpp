// 286. Walls and Gates
// Approach: Multi-source BFS starting from every gate (value 0) simultaneously,
// filling each empty room (INF) with the shortest distance to the nearest gate.
// Walls (-1) block movement.
// Time: O(m*n)  Space: O(m*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        const int INF = 2147483647;
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) q.push({i, j});
            }
        }

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && rooms[nr][nc] == INF) {
                    rooms[nr][nc] = rooms[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};

int main() {
    const int INF = 2147483647;
    vector<vector<int>> rooms = {
        {INF, -1, 0, INF},
        {INF, INF, INF, -1},
        {INF, -1, INF, -1},
        {0, -1, INF, INF}
    };
    Solution sol;
    sol.wallsAndGates(rooms);
    for (auto& row : rooms) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }
    return 0;
}
