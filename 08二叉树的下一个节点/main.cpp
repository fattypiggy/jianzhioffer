#include <iostream>
using namespace std;
struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next; // 指向父节点的指针
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
/**
 * 如果一个节点有右子树，那么返回右子树最左节点
 * 如果节点是它父亲节点的左节点，那么返回他的父节点
 * 如果节点是它父亲的右节点，且它没有右子树，那么沿着父节点的指针向上遍历，直到找到是它父节点的左节点的节点，返回其父节点，若没有，则返回nullptr
 * @param pNode 指定节点
 * @return pNext pNode下一个中序遍历序列的节点指针
 */
TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if (pNode == nullptr)
        return nullptr;
    TreeLinkNode *pNext = nullptr;
    if (pNode->right != nullptr) { // 有右子树
        pNext = pNode->right;
        while (pNext->left != nullptr)
            pNext = pNext->left;
    } else { // 无右子树
        TreeLinkNode *pParent = pNode->next;
        if (pParent != nullptr && pParent->left == pNode) // 是其父节点的左节点
            pNext = pParent;
        else { // 是其父节点的右节点
            TreeLinkNode *pCurrent = pNode;
            while (pParent != nullptr && pCurrent == pParent->right) {
                pCurrent = pParent;
                pParent = pCurrent->next;
            }
            pNext = pParent;
        }
    }
    return pNext;
}
int main() {
    TreeLinkNode *n1 = new TreeLinkNode(1);
    TreeLinkNode *n2 = new TreeLinkNode(2);
    TreeLinkNode *n3 = new TreeLinkNode(3);
    TreeLinkNode *n4 = new TreeLinkNode(4);
    TreeLinkNode *n5 = new TreeLinkNode(5);
    TreeLinkNode *n6 = new TreeLinkNode(6);
    TreeLinkNode *n7 = new TreeLinkNode(7);
    TreeLinkNode *n8 = new TreeLinkNode(8);
    TreeLinkNode *n9 = new TreeLinkNode(9);
    n1->left = n2;
    n1->right = n3;
    n2->next = n1;
    n2->left = n4;
    n2->right = n5;
    n3->next = n1;
    n3->left = n6;
    n3->right = n7;
    n4->next = n2;
    n5->next = n2;
    n5->left = n8;
    n5->right = n9;
    n6->next = n3;
    n7->next = n3;
    n8->next = n5;
    n9->next = n5;
    cout << GetNext(n1)->val << endl << GetNext(n4)->val << endl << GetNext(n9)->val << endl;
    if (!GetNext(n7)) cout << "nullptr" << endl;
    return 0;
}
