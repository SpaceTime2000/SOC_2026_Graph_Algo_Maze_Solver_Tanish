// 332. Reconstruct Itinerary
// Approach: Hierholzer's algorithm for finding an Eulerian path. Store
// destinations for each airport in a sorted multiset so the lexicographically
// smallest unused ticket is always tried first; do a post-order DFS and
// reverse the resulting route.
// Time: O(E log E)  Space: O(E)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto& t : tickets) {
            graph[t[0]].insert(t[1]);
        }

        vector<string> route;
        dfs("JFK", graph, route);
        reverse(route.begin(), route.end());
        return route;
    }

private:
    void dfs(const string& airport, unordered_map<string, multiset<string>>& graph, vector<string>& route) {
        while (!graph[airport].empty()) {
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(next, graph, route);
        }
        route.push_back(airport);
    }
};

int main() {
    vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    Solution sol;
    auto result = sol.findItinerary(tickets);
    for (auto& s : result) cout << s << " ";
    cout << endl;
    return 0;
}
