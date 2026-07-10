// 1584. Min Cost to Connect All Points
// Approach: Minimum Spanning Tree via Prim's algorithm. Repeatedly pick the
// unvisited point with the smallest known connection cost to the growing
// tree, using Manhattan distance as edge weight.
// Time: O(n^2 log n)  Space: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);
        minDist[0] = 0;
        int totalCost = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});

        int edgesUsed = 0;
        while (edgesUsed < n) {
            auto [d, u] = pq.top(); pq.pop();
            if (inMST[u]) continue;
            inMST[u] = true;
            totalCost += d;
            edgesUsed++;

            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }
        return totalCost;
    }
};

int main() {
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    Solution sol;
    cout << sol.minCostConnectPoints(points) << endl;
    return 0;
}
