#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int size = postorder.size();
        if (size == 0) return true;
        int root = postorder[size - 1];
        // 分段
        int i = 0;
        for(; i < size - 1; i++) {
            if (postorder[i] > root)
                break;
        }
        // 检查右侧是否全部大于root
        int j = i;
        for (; j < size - 1; j++) {
            if (postorder[j] < root)
                return false;
        }

        // 没有左子树返回true，有左子树递归判断。
        bool left = true;
        if (i > 0) {
            vector<int> left_part(postorder.begin(), postorder.begin() + i);
            left = verifyPostorder(left_part);
        }

        // 没有右子树返回true，有右子树递归判断。
        bool right = true;
        if (i < size - 1) {
            vector<int> right_part(postorder.begin() + i, postorder.end() - 1); // 注意截取边界 end - 1
            right = verifyPostorder(right_part);
        }
        return (left & right);
    }
};
int main() {
    Solution s;
    vector<int> v1{1,6,3,2,5};
    vector<int> v2{1,3,2,6,5};
    cout << s.verifyPostorder(v1); // expected: false
    cout << s.verifyPostorder(v2); // expected: true;
    return 0;
}
