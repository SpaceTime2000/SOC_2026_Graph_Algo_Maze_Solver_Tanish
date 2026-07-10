// 721. Accounts Merge
// Approach: Union-Find over account indices. Union two accounts whenever they
// share an email. Then group all emails by their root account and attach the
// owner's name.
// Time: O(N * K log(N*K))  Space: O(N*K)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<string, int> emailToAccount;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (int)accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if (emailToAccount.count(email)) {
                    unite(i, emailToAccount[email]);
                } else {
                    emailToAccount[email] = i;
                }
            }
        }

        unordered_map<int, set<string>> rootToEmails;
        for (auto& entry : emailToAccount) {
            int root = find(entry.second);
            rootToEmails[root].insert(entry.first);
        }

        vector<vector<string>> result;
        for (auto& entry : rootToEmails) {
            vector<string> merged;
            merged.push_back(accounts[entry.first][0]);
            merged.insert(merged.end(), entry.second.begin(), entry.second.end());
            result.push_back(merged);
        }
        return result;
    }

private:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }
};

int main() {
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    Solution sol;
    auto result = sol.accountsMerge(accounts);
    for (auto& acc : result) {
        for (auto& s : acc) cout << s << " ";
        cout << endl;
    }
    return 0;
}
