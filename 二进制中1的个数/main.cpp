#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * 求数字的二进制形式中1的个数
     * @param n 待求数字
     * @return 1的个数
     */
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= n - 1; // n &= (n-1)相当于把n最右边的1消去，所以count等于1的个数
            count++;
        }
        return count;
    }
};
int main() {
    Solution s;
    cout << s.hammingWeight(9) << endl;
    return 0;
}
