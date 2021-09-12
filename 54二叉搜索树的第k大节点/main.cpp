#include <iostream>
#include "../Utils/TreeNode.h"
using namespace std;
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return res;
    }
private:
    int k;
    int res;
    // 中序遍历是升序，镜像中序遍历是降序。
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->right);
        k--;
        if (k == 0) {
            res = root->val;
            return;
        }
        dfs(root->left);
    }
};
int main() {
    Solution s;
    string input1 = "[3,1,4,null,2]", input2 = "[5,3,6,2,4,null,null,1]";
    int k = 4;
    TreeNode *root1 = stringToTreeNode(input1);
    TreeNode *root2 = stringToTreeNode(input2);
    cout << s.kthLargest(root1, k) << endl;
    cout << s.kthLargest(root2, k) << endl;
    return 0;
}
