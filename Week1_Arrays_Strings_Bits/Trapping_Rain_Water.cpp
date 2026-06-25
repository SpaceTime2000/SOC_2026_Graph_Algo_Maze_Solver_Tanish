// Trapping Rain Water

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, lMax = 0, rMax = 0, res = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                lMax = max(lMax, height[l]);
                res += lMax - height[l++];
            } else {
                rMax = max(rMax, height[r]);
                res += rMax - height[r--];
            }
        }
        return res;
    }
};
