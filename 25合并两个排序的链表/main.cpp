#include <iostream>
#include "../Utils/ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *head = nullptr, *tail = nullptr;
        head = new ListNode(-1);
        tail = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 == nullptr ? l2 : l1;
        return head->next;
    }
};
int main() {
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(4);
    ListNode *l2 = new ListNode(1);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    l1->next = n1;
    n1->next = n2;
    l2->next = n3;
    n3->next = n4;
    ListNode *res = s.mergeTwoLists(l1, l2);
    while (res != nullptr) {
        cout << res->val;
        res = res->next;
    }
    return 0;
}
