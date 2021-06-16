#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) return nullptr;
    int i = 0;
    for (; i < preorder.size(); ++i) {
        if (preorder[0] == inorder[i]) break;
    }
    vector<int> pre_l(preorder.begin() + 1, preorder.begin() + i + 1);
    vector<int> in_l(inorder.begin(), inorder.begin() + i);
    vector<int> pre_r(preorder.begin() + i + 1, preorder.end());
    vector<int> in_r(inorder.begin() + i + 1, inorder.end());
    TreeNode *root =  new TreeNode(preorder[0]);
    root->left = buildTree(pre_l, in_l);
    root->right = buildTree(pre_r, in_r);
    return root;
}
int main() {
    vector<int> preorder{3,9,20,15,7}, inorder{9,3,15,20,7};
    TreeNode *root = buildTree(preorder, inorder);
    return 0;
}
