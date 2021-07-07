#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) return nullptr;
        if (head->val == val) {
            head = head->next;
            return head;
        }

        ListNode *pcurrent = head;
        ListNode *pnext = pcurrent->next;
        while (pcurrent) {
            if (pnext->val == val) {
                pcurrent->next = pnext->next;
                break;
            }
            pcurrent = pnext;
            pnext = pcurrent->next;
        }
        return head;
    }
};
int main() {
    ListNode n0 = ListNode(4), n1 = ListNode(5), n2 = ListNode(1), n3 = ListNode(9);
    ListNode *head = &n0, *p1=&n1, *p2 = &n2, *p3 = &n3;
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    Solution s;
    std::cout << s.deleteNode(head, 1)->val;
    return 0;
}
