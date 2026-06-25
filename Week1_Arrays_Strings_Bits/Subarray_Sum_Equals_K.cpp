// Subarray Sum Equals K

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> pre;
        pre[0] = 1;
        int sum = 0, cnt = 0;
        for (int n : nums) {
            sum += n;
            if (pre.count(sum-k)) cnt += pre[sum-k];
            pre[sum]++;
        }
        return cnt;
    }
};
