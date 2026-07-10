// 323. Number of Connected Components in an Undirected Graph
// Approach: Union-Find (Disjoint Set Union) with path compression. Start with
// n components and union endpoints of every edge, decrementing the component
// count each time two previously separate sets merge.
// Time: O(V + E * alpha(V))  Space: O(V)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        int components = n;
        for (auto& e : edges) {
            if (unite(e[0], e[1])) components--;
        }
        return components;
    }

private:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        parent[ra] = rb;
        return true;
    }
};

int main() {
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    Solution sol;
    cout << sol.countComponents(5, edges) << endl;
    return 0;
}
