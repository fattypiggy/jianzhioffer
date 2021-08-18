#include <iostream>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        copyNodes(head);
        connectRandom(head);
        return reconnect(head);
    }
private:
    /**
     * 复制每一个Node使之连接在当前被复制的Node后面。
     * @example head = [A, B, C], 操作后 head = [A, A', B, B', C, C']
     * @param head
     */
    void copyNodes(Node* head) {
        if (head == nullptr) return;
        Node* pHead = head;
        while (pHead != nullptr) {
            Node* cloned = new Node(pHead->val);
            cloned->next = pHead->next;
            pHead->next = cloned;
            pHead = cloned->next;
        }
    }
    /**
     * 连接random
     * @example A'->random = B'
     * @param head
     */
    void connectRandom(Node* head) {
        if (head == nullptr) return;
        Node* pHead = head;
        while (pHead != nullptr) {
            Node* cloned = pHead->next;
            if (pHead->random != nullptr)
                cloned->random = pHead->random->next;
            pHead = cloned->next;
        }

    }
    /**
     * 取head的偶数节点，重新连接为head'，并且head恢复为[A, B, C]
     * @example head = [A, A', B, B', C, C'] => head = [A, B, C], head' = [A', B', C']
     * @param head
     * @return head'
     */
    Node* reconnect(Node* head) {
        if (head == nullptr) return nullptr;
        Node* pHead = head;
        Node *copy = nullptr, *pNode = nullptr;
        if (pHead != nullptr) {
            copy = pNode = head->next; // copy = A'
            pHead = copy->next; // pHead = B;
            head->next = pHead; // head->next = B;
        }

        while (pHead != nullptr) {
            pNode->next = pHead->next; // A' -> next = B'
            pNode = pHead->next;
            pHead->next = pNode->next; // B->next = C;
            pHead = pHead->next;
        }
        return copy;
    }
};
int main() {
    Solution s;
    Node *head = new Node(7);
    Node *n1 = new Node(13);
    Node *n2 = new Node(11);
    Node *n3 = new Node(10);
    Node *n4 = new Node(1);
    head->next = n1, n1->next = n2, n2->next = n3, n3->next = n4;
    n1->random = head, n2->random = n4, n3->random = n2, n4->random = head;
    s.copyRandomList(head);
    return 0;
}
