// 417. Pacific Atlantic Water Flow
// Approach: Reverse thinking - run multi-source DFS from every Pacific border
// cell and every Atlantic border cell, flowing "uphill" (to cells with height
// >= current). A cell reachable from both oceans is part of the answer.
// Time: O(m*n)  Space: O(m*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, m, n);
            dfs(heights, atlantic, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, m, n);
            dfs(heights, atlantic, m - 1, j, m, n);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c, int m, int n) {
        visited[r][c] = true;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc, m, n);
            }
        }
    }
};

int main() {
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    Solution sol;
    auto result = sol.pacificAtlantic(heights);
    for (auto& cell : result) cout << "[" << cell[0] << "," << cell[1] << "] ";
    cout << endl;
    return 0;
}
