#include <iostream>
#include <cmath>
#include <algorithm>
#include "../Utils/TreeNode.h"
using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return recur(root) == -1 ? false : true;
    }
private:
    /**
     * 后序遍历，计算子树之间的深度差，若小于等于1，则root的深度为max(left, right)+1, 否则直接返回-1(false)。
     * @param root
     * @return 
     */
    int recur(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = recur(root->left); // 左子树的depth
        if (left == -1) return -1; // 左子树不满足平衡二叉树，提前返回。
        int right = recur(root->right); // 右子树的depth
        if (right == -1) return -1; // 右子树不满足平衡二叉树，提前返回。
        return abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
};
int main() {
    Solution s;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode *root = stringToTreeNode(input);
    cout << s.isBalanced(root) << endl;
    return 0;
}
