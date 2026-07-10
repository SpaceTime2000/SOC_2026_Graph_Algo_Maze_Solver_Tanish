// 684. Redundant Connection
// Approach: Union-Find. Process edges in order; the first edge that connects
// two nodes already in the same component is the redundant edge that creates
// the cycle.
// Time: O(V * alpha(V))  Space: O(V)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;

        for (auto& e : edges) {
            int a = e[0], b = e[1];
            int ra = find(a), rb = find(b);
            if (ra == rb) return e;
            parent[ra] = rb;
        }
        return {};
    }

private:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
};

int main() {
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    Solution sol;
    vector<int> result = sol.findRedundantConnection(edges);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
