// 733. Flood Fill
// Approach: BFS from (sr, sc), changing every connected pixel that matches the
// original color to the new color.
// Time: O(m*n)  Space: O(m*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        if (startColor == color) return image;
        int m = image.size(), n = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == startColor) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};

int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    Solution sol;
    auto result = sol.floodFill(image, 1, 1, 2);
    for (auto& row : result) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }
    return 0;
}
