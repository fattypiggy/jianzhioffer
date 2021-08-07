// https://leetcode-cn.com/problems/linked-list-cycle-ii/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *fast = head, *slow = head;
        while (true) {
            // fast == nullptr 必须要判断
            if (slow == nullptr || fast == nullptr || fast->next == nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);
    ListNode *n3 = new ListNode(4);
    ListNode *n4 = new ListNode(5);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    ListNode *result = s.detectCycle(head);
    cout << (result == nullptr ? -1 : result->val);
    return 0;
}
