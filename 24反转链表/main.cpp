#include <iostream>
#include "../Utils/ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *left = nullptr, *middle = head, *right = head->next;
        while (right != nullptr) {
            middle->next = left;
            left = middle;
            middle = right;
            right = right->next;
        }
        middle->next = left;
        return middle;
    }
};
int main() {
    ListNode *head = new ListNode(0);
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
//    head->next = n1;
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
    Solution s;
    s.reverseList(head);
    return 0;
}
