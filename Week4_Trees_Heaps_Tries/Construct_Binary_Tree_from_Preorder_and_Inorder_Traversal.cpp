// Construct Binary Tree from Preorder and Inorder Traversal

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> idx;
        for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
        int pre = 0;
        function<TreeNode*(int,int)> build = [&](int l, int r) -> TreeNode* {
            if (l > r) return nullptr;
            int rootVal = preorder[pre++];
            TreeNode* node = new TreeNode(rootVal);
            int mid = idx[rootVal];
            node->left = build(l, mid-1);
            node->right = build(mid+1, r);
            return node;
        };
        return build(0, inorder.size()-1);
    }
};
