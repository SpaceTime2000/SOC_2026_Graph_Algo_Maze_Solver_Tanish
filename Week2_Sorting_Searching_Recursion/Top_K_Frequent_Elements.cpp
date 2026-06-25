// Top K Frequent Elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums) freq[n]++;
        vector<vector<int>> bucket(nums.size()+1);
        for (auto& p : freq) bucket[p.second].push_back(p.first);
        vector<int> res;
        for (int i = bucket.size()-1; i >= 0 && res.size() < k; i--)
            for (int n : bucket[i]) res.push_back(n);
        return res;
    }
};
