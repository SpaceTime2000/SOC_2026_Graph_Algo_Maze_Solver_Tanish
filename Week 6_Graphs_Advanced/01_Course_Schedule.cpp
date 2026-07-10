// 207. Course Schedule
// Approach: Detect a cycle in the directed prerequisite graph using Kahn's
// algorithm (BFS topological sort). If we can topologically order all
// courses, there is no cycle and finishing is possible.
// Time: O(V+E)  Space: O(V+E)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int visited = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited++;
            for (int v : adj[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return visited == numCourses;
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    Solution sol;
    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    return 0;
}
