#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
using namespace std;
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    // pre用于记录cur左侧的节点，即上一次迭代中的cur
    // 全部迭代完后，pre指向尾节点
    Node *head, *pre;
    void dfs(Node* cur) {
        if (cur == nullptr) return;
        dfs(cur->left);
        if (pre != nullptr) pre->right = cur;
        else head = cur; // 最左侧的节点
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};
int main() {
    Solution s;
    return 0;
}
