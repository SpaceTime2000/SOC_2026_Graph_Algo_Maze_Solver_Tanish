// Copy List with Random Pointer

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* cur = head;
        while (cur) { mp[cur] = new Node(cur->val); cur = cur->next; }
        cur = head;
        while (cur) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};
