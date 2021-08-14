#include <iostream>
#include <vector>
#include <queue>
#include "../Utils/TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            v.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            q.pop();
        }
        return v;
    }
};
int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    TreeNode* n1 = new TreeNode(9);
    TreeNode* n2 = new TreeNode(20);
    TreeNode* n3 = new TreeNode(15);
    TreeNode* n4 = new TreeNode(7);
    root->left = n1;
//    root->right = n2;
//    n2->left = n3;
//    n2->right = n4;
    s.levelOrder(root);
    return 0;
}
