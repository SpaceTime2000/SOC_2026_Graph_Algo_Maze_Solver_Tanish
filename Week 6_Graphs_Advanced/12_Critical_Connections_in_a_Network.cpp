// 1192. Critical Connections in a Network
// Approach: Tarjan's bridge-finding algorithm. Track discovery time and the
// lowest reachable discovery time (low-link) for each node via DFS. An edge
// (u, v) is a bridge if low[v] > disc[u], meaning v's subtree cannot reach u
// or any ancestor without that edge.
// Time: O(V+E)  Space: O(V+E)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.assign(n, {});
        for (auto& c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        disc.assign(n, -1);
        low.assign(n, -1);
        timer = 0;
        result.clear();

        dfs(0, -1);
        return result;
    }

private:
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<vector<int>> result;
    int timer;

    void dfs(int u, int parent) {
        disc[u] = low[u] = timer++;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (disc[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    result.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
};

int main() {
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    Solution sol;
    auto result = sol.criticalConnections(4, connections);
    for (auto& edge : result) cout << "[" << edge[0] << "," << edge[1] << "] ";
    cout << endl;
    return 0;
}
