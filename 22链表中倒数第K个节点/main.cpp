#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;
        int count = 0;
        while (count < k) {
            if (fast == nullptr) return nullptr;
            fast = fast->next;
            count++;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
int main() {
    Solution s;
    ListNode *head = new ListNode(0);
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    ListNode * result = s.getKthFromEnd(head, 2);
    cout<<(result == nullptr ? -1 : result->val);
    return 0;
}
