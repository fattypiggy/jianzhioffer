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

#endif //UTILS_TREENODE_H
