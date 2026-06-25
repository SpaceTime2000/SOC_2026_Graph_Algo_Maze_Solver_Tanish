// Binary Tree Maximum Path Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int res = INT_MIN;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = max(0, dfs(node->left));
        int r = max(0, dfs(node->right));
        res = max(res, node->val + l + r);
        return node->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
