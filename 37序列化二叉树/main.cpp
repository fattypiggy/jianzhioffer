#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include "../Utils/TreeNode.h"
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        ostringstream output;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            if (node == nullptr) output << "#" << " ";
            else{
                output << node->val << " "; // 空格是必须的
                q.push(node->left);
                q.push(node->right);
            }
            q.pop();
        }
        return output.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream input(data);
        string str;
        vector<TreeNode*> nodes;
        int amount = 0; // 用来记录0-i之间多少个nullptr
        while (input >> str) {
            if (str == "#") nodes.push_back(nullptr);
            else nodes.push_back(new TreeNode(stoi(str)));
        }
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i] == nullptr) {
                amount++;
                continue;
            }
            // 关键代码，nodes[i]左子树的下标为 2 * (i-amount) + 1，右子树的下标为 2 * (i-amount) + 2
            nodes[i]->left = nodes[2*(i-amount) + 1];
            nodes[i]->right = nodes[2*(i-amount) + 2];
        }
        return nodes[0];
    }
};
int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;
    Codec c;
    c.deserialize(c.serialize(root));
    return 0;
}
