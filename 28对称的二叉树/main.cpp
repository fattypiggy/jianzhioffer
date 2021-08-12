#include <iostream>
#include "../Utils/TreeNode.h"
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        // left 和 right都为nullptr
        if (!left && !right)
            return true;
        // left为nullptr或right为nullptr或left->val != right->val
        if (!left || !right || left->val != right->val)
            return false;
        else
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
