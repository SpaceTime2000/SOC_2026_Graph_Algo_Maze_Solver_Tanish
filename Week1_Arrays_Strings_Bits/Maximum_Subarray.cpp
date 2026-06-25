// Maximum Subarray

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxS = nums[0], curS = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curS = max(nums[i], curS + nums[i]);
            maxS = max(maxS, curS);
        }
        return maxS;
    }
};
