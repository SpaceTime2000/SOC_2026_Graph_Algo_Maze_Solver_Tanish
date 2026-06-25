// Reorder List

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next; fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (second) {
            ListNode* tmp = second->next;
            second->next = prev; prev = second; second = tmp;
        }
        ListNode* first = head; second = prev;
        while (second) {
            ListNode* t1 = first->next, *t2 = second->next;
            first->next = second; second->next = t1;
            first = t1; second = t2;
        }
    }
};
