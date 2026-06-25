// Best Time to Buy and Sell Stock

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX, res = 0;
        for (int p : prices) {
            minP = min(minP, p);
            res = max(res, p - minP);
        }
        return res;
    }
};
