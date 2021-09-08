#include <iostream>
#include <unordered_map>
#include "../Utils/ListNode.h"
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *pA = new ListNode(-1);
        pA->next = headA;
        ListNode *pB = new ListNode(-1);
        pB->next = headB;
        unordered_map<ListNode*, int> um;
        while (pA->next != nullptr) {
            um[pA->next]++;
            pA = pA->next;
        }
        while (pB->next != nullptr) {
            if (um[pB->next] == 0)
                pB = pB->next;
            else
                return pB->next;
        }
        return nullptr;
    }

    // 双指针版本
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *pA = headA, *pB = headB;
        // pA和pB分别往后遍历，pA走到nullptr后开始指向pB，pB同理。
        // 直到pA和pB相同（相交），或者pA和pB都为nullptr（不相交）
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};
int main() {
    // 通过
    return 0;
}
