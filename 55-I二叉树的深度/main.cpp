#include <iostream>
#include "../Utils/TreeNode.h"
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        this->res = 0;
        dfs(root, 0);
        return res;
    }
private:
    int res;
    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) return;
        depth++;
        res = max(res, depth);
        dfs(root->left, depth);
        dfs(root->right, depth);
    }
};
int main() {
    Solution s;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode *root = stringToTreeNode(input);
    cout << s.maxDepth(root) << endl;
    return 0;
}
