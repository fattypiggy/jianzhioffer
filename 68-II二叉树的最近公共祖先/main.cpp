#include <iostream>
#include <unordered_map>
#include "../Utils/TreeNode.h"
using namespace std;
class Solution {
private:
    // fa存储父节点信息
    unordered_map<int, TreeNode*> fa;
    // visited用于从下到上往回追溯父节点
    unordered_map<int, bool> visited;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        fa[root->val] = nullptr;
        dfs(root);
        while (p) {
            visited[p->val] = true;
            p = fa[p->val];
        }
        while (q) {
            if (visited[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;
    }
    void dfs(TreeNode *root) {
        if (root->left) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
};

class Solution2 {
public:
    // 递归
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) return right;
        else if (right == nullptr) return left;
        else return root;
    }
};
int main() {
    return 0;
}
