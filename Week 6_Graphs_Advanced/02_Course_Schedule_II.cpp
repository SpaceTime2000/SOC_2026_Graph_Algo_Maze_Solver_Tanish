// 210. Course Schedule II
// Approach: Kahn's algorithm (BFS topological sort). Repeatedly remove
// zero-indegree nodes, appending them to the order. If all courses get
// ordered, return the order; otherwise a cycle exists and we return {}.
// Time: O(V+E)  Space: O(V+E)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int course = p[0], pre = p[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }

        if ((int)order.size() != numCourses) return {};
        return order;
    }
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    Solution sol;
    vector<int> order = sol.findOrder(numCourses, prerequisites);
    for (int c : order) cout << c << " ";
    cout << endl;
    return 0;
}
