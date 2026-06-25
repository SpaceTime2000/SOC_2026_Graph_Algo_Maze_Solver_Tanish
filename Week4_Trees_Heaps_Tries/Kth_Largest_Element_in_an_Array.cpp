// Kth Largest Element in an Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minH;
        for (int n : nums) {
            minH.push(n);
            if (minH.size() > k) minH.pop();
        }
        return minH.top();
    }
};
