// Permutations

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        function<void(int)> bt = [&](int start) {
            if (start == nums.size()) { res.push_back(nums); return; }
            for (int i = start; i < nums.size(); i++) {
                swap(nums[start], nums[i]);
                bt(start+1);
                swap(nums[start], nums[i]);
            }
        };
        bt(0);
        return res;
    }
};
