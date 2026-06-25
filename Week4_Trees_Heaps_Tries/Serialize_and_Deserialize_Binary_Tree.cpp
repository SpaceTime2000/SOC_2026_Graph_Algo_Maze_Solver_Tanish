// Serialize and Deserialize Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "N,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) q.push(token);
        function<TreeNode*()> dfs = [&]() -> TreeNode* {
            string val = q.front(); q.pop();
            if (val == "N") return nullptr;
            TreeNode* node = new TreeNode(stoi(val));
            node->left = dfs();
            node->right = dfs();
            return node;
        };
        return dfs();
    }
};
