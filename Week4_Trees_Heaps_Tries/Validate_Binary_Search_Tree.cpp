// Validate Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root, long lo=LONG_MIN, long hi=LONG_MAX) {
        if (!root) return true;
        if (root->val <= lo || root->val >= hi) return false;
        return isValidBST(root->left, lo, root->val) &&
               isValidBST(root->right, root->val, hi);
    }
};
