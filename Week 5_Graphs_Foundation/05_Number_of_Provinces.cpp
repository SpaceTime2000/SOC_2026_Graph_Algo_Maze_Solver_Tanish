// 547. Number of Provinces
// Approach: Treat isConnected as an adjacency matrix and count connected
// components via DFS.
// Time: O(n^2)  Space: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(isConnected, visited, i, n);
            }
        }
        return provinces;
    }

private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city, int n) {
        visited[city] = true;
        for (int next = 0; next < n; next++) {
            if (isConnected[city][next] == 1 && !visited[next]) {
                dfs(isConnected, visited, next, n);
            }
        }
    }
};

int main() {
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    Solution sol;
    cout << "Provinces: " << sol.findCircleNum(isConnected) << endl;
    return 0;
}
