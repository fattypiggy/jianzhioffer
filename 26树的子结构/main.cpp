#include "../Utils/TreeNode.h"
using namespace std;
using namespace std;
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool result = false;
        // A为nullptr时B肯定不是A的子结构
        // B为nullptr时，题目规定为不是A的子结构（和实事规定相反）
        if (A == nullptr || B == nullptr) return false;

        if (A->val == B->val)
            result = isEqual(A, B);
        if (!result)
                result = isSubStructure(A->left, B);
        if (!result)
                result = isSubStructure(A->right, B);
        return result;
    }

private:
    bool isEqual(TreeNode* A, TreeNode* B) {
        // 这里一定要先判断B
        if (B == nullptr)
            return true;
        if (A == nullptr)
            return false;
        if (A->val != B->val)
            return false;
        return isEqual(A->left, B->left) && isEqual(A->right, B->right);
    }
};
int main() {
    Solution s;
    return 0;
}
