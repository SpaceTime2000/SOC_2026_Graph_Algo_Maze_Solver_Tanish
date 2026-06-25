// Longest Substring Without Repeating Characters

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int res = 0, l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (mp.count(s[r]) && mp[s[r]] >= l)
                l = mp[s[r]] + 1;
            mp[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
