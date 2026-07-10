// 743. Network Delay Time
// Approach: Dijkstra's shortest path algorithm from source node k using a
// min-heap. The answer is the maximum shortest distance to any node (the last
// node to receive the signal), or -1 if some node is unreachable.
// Time: O(E log V)  Space: O(V+E)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& edge : adj[u]) {
                int v = edge.first, w = edge.second;
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;
    }
};

int main() {
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    Solution sol;
    cout << sol.networkDelayTime(times, 4, 2) << endl;
    return 0;
}
