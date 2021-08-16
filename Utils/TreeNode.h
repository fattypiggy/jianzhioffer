//
// Created by 经纬 on 2021/8/7.
//
#ifndef UTILS_TREENODE_H
#define UTILS_TREENODE_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
std::string treeNodeToString(TreeNode* root);
void trimLeftTrailingSpaces(std::string &input);
void trimRightTrailingSpaces(std::string &input);
void prettyPrintTree(TreeNode* node, std::string prefix, bool isLeft);
TreeNode* stringToTreeNode(std::string input);
#endif //UTILS_TREENODE_H
