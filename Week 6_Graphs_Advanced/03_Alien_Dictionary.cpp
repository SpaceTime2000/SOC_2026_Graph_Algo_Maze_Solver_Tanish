// 269. Alien Dictionary
// Approach: Build a precedence graph by comparing each pair of adjacent words
// at their first differing character, then topologically sort (Kahn's) the
// alphabet. A word that is a longer "prefix violation" of the next word makes
// the ordering invalid.
// Time: O(C) where C = total length of all words  Space: O(1) (<=26 letters)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for (const string& w : words) {
            for (char c : w) indegree[c] = 0;
        }

        for (int i = 0; i + 1 < (int)words.size(); i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            bool foundDiff = false;

            for (int j = 0; j < minLen; j++) {
                char c1 = w1[j], c2 = w2[j];
                if (c1 != c2) {
                    if (!adj[c1].count(c2)) {
                        adj[c1].insert(c2);
                        indegree[c2]++;
                    }
                    foundDiff = true;
                    break;
                }
            }
            if (!foundDiff && w1.size() > w2.size()) return "";
        }

        queue<char> q;
        for (auto& entry : indegree) {
            if (entry.second == 0) q.push(entry.first);
        }

        string result;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            result += c;
            for (char next : adj[c]) {
                if (--indegree[next] == 0) q.push(next);
            }
        }

        return (int)result.size() == (int)indegree.size() ? result : "";
    }
};

int main() {
    vector<string> words = {"wrt","wrf","er","ett","rftt"};
    Solution sol;
    cout << sol.alienOrder(words) << endl;
    return 0;
}
