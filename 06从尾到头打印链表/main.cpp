#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
vector<int> reversePrint(ListNode* head) {
    stack<int> s;
    vector<int>v;
    ListNode *p = head;
    if (head != nullptr)
        s.push(head->val);
    else // 不要忘记这个
        return v;
    while (p->next != nullptr) {
        p = p->next;
        s.push(p->val);
    }
    while (s.size()) {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

int main() {
//    ListNode *s1 = new ListNode(1);
//    ListNode *s2 = new ListNode(2);
//    ListNode *s3 = new ListNode(3);
    ListNode *head = nullptr;
//    head->next = s3;
//    s3->next = s2;
    vector<int> v = reversePrint(head);
    return 0;
}
