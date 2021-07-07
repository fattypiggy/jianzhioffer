/**
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 */
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *pCurrent = dummy;
        while (pCurrent->next && pCurrent->next->next) {
            if (pCurrent->next->val == pCurrent->next->next->val) {
                int value = pCurrent->next->val;
                while (pCurrent->next && pCurrent->next->val == value) {
                    pCurrent->next = pCurrent->next->next;
                }
            } else {
                pCurrent = pCurrent->next;
            }
        }
        return dummy->next;
    }
};
int main() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(3);
    ListNode *p5 = new ListNode(4);
    ListNode *p6 = new ListNode(4);
    ListNode *p7 = new ListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    Solution s;
    ListNode * head = s.deleteDuplicates(p1);
    return 0;
}
