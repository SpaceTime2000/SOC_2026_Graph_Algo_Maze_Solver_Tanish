// Diameter of Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int res = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = dfs(node->left), r = dfs(node->right);
        res = max(res, l + r);
        return 1 + max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};
