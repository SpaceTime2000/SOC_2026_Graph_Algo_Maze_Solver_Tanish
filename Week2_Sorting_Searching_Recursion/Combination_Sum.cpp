// Combination Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        function<void(int,int)> bt = [&](int start, int rem) {
            if (rem == 0) { res.push_back(curr); return; }
            for (int i = start; i < candidates.size(); i++) {
                if (candidates[i] > rem) continue;
                curr.push_back(candidates[i]);
                bt(i, rem - candidates[i]);
                curr.pop_back();
            }
        };
        bt(0, target);
        return res;
    }
};
