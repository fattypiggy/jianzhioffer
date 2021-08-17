#include <iostream>
#include <string>
#include <vector>
#include "../Utils/TreeNode.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        recur(root, target);
        return matrix;
    }
private:
    vector<int> v;
    vector<vector<int>> matrix;
    /**
     * 回溯法进行二叉树的前序遍历，并且记录路径。
     * @param root
     * @param target
     */
    void recur(TreeNode* root, int target) {
        if (root == nullptr) return;
        v.push_back(root->val);
        target -= root->val;
        if (target == 0 && root->left == nullptr && root->right == nullptr)
            matrix.push_back(v);
        recur(root->left, target);
        recur(root->right, target);
        v.pop_back();
    }
};
int main() {
    Solution s;
    string str = "[5,4,8,11,null,13,4,7,2,null,null,5,1]";
    TreeNode *tree = stringToTreeNode(str);
    s.pathSum(tree, 22);
    return 0;
}
