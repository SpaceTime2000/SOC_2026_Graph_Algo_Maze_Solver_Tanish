// 787. Cheapest Flights Within K Stops
// Approach: Bellman-Ford style relaxation limited to k+1 rounds (k+1 edges),
// since Dijkstra does not naturally respect a "max stops" constraint. Each
// round relaxes every edge using distances frozen from the previous round.
// Time: O(K * E)  Space: O(V)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (auto& f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    Solution sol;
    cout << sol.findCheapestPrice(3, flights, 0, 2, 1) << endl;
    return 0;
}
