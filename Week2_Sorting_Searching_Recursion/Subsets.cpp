// Subsets

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        function<void(int)> bt = [&](int start) {
            res.push_back(curr);
            for (int i = start; i < nums.size(); i++) {
                curr.push_back(nums[i]);
                bt(i+1);
                curr.pop_back();
            }
        };
        bt(0);
        return res;
    }
};
