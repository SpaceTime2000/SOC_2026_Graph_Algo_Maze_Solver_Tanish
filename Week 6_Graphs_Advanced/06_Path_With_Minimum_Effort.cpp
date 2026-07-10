// 1631. Path With Minimum Effort
// Approach: Dijkstra variant where the "distance" being minimized is the
// maximum absolute height difference along the path rather than a sum of
// weights. A min-heap always expands the currently smallest possible effort.
// Time: O(m*n log(m*n))  Space: O(m*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        effort[0][0] = 0;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [e, r, c] = pq.top(); pq.pop();
            if (r == m - 1 && c == n - 1) return e;
            if (e > effort[r][c]) continue;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newEffort = max(e, abs(heights[nr][nc] - heights[r][c]));
                    if (newEffort < effort[nr][nc]) {
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    Solution sol;
    cout << sol.minimumEffortPath(heights) << endl;
    return 0;
}
