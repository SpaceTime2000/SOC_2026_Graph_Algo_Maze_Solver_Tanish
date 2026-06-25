// Implement Trie (Prefix Tree)

#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        Node* ch[26] = {};
        bool end = false;
    };
    Node* root;
public:
    Trie() { root = new Node(); }
    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->ch[c-'a']) cur->ch[c-'a'] = new Node();
            cur = cur->ch[c-'a'];
        }
        cur->end = true;
    }
    bool search(string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->ch[c-'a']) return false;
            cur = cur->ch[c-'a'];
        }
        return cur->end;
    }
    bool startsWith(string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            if (!cur->ch[c-'a']) return false;
            cur = cur->ch[c-'a'];
        }
        return true;
    }
};
