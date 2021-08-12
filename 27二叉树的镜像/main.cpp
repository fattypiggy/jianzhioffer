#include <iostream>
#include "../Utils/TreeNode.h"
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root != nullptr) {
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            mirrorTree(root->left);
            mirrorTree(root->right);
        }
        return root;
    }
};
int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    TreeNode *n5 = new TreeNode(6);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    Solution s;
    s.mirrorTree(root);
    return 0;
}
