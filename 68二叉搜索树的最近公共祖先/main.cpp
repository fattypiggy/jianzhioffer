#include <iostream>
#include "../Utils/TreeNode.h"
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        while (root != nullptr) {
            if (root->val > p->val && root->val > q->val)
                root = root->left;
            else if (root->val < p->val && root->val < q->val)
                root = root->right;
            else
                break;
        }
        return root;
    }
};
int main() {
    // no test case
    return 0;
}
