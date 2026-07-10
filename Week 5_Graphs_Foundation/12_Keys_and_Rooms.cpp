// 841. Keys and Rooms
// Approach: DFS starting from room 0 (using an explicit stack), visiting every
// room reachable using collected keys. If every room ends up visited, all
// rooms are reachable.
// Time: O(V+E)  Space: O(V)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(0);
        visited[0] = true;
        int visitedCount = 1;

        while (!st.empty()) {
            int room = st.top(); st.pop();
            for (int key : rooms[room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    visitedCount++;
                    st.push(key);
                }
            }
        }
        return visitedCount == n;
    }
};

int main() {
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    Solution sol;
    cout << (sol.canVisitAllRooms(rooms) ? "true" : "false") << endl;
    return 0;
}
