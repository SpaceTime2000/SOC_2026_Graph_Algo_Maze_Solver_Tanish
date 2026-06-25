// Valid Anagram

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int cnt[26] = {};
        for (char c : s) cnt[c-'a']++;
        for (char c : t) if (--cnt[c-'a'] < 0) return false;
        return true;
    }
};
