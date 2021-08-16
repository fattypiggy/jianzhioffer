#include <iostream>
#include <vector>
#include <deque>
#include "../Utils/TreeNode.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> v;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int level = 1;
        while (!dq.empty()) {
            vector<int> v_level;
            deque<TreeNode*> dq_level;

            // q to q_level, q to v_level
            while (!dq.empty()) {
                if (level & 1) {
                    TreeNode *node = dq.front();
                    v_level.push_back(node->val);
                    dq_level.push_back(node);
                    dq.pop_front();
                } else {
                    TreeNode * node = dq.back();
                    v_level.push_back(node->val);
                    dq_level.push_front(node);
                    dq.pop_back();
                }
            }
            v.push_back(v_level);
            while (!dq_level.empty()) {
                TreeNode *node = dq_level.front();
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
                dq_level.pop_front();
            }
            level++;
        }
        return v;
    }
};
int main() {
    Solution s;
    string str;
    cin >> str;
    TreeNode* tree = stringToTreeNode(str);
    s.levelOrder(tree);
    return 0;
}