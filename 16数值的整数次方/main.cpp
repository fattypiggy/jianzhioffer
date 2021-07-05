#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            if (n == INT32_MIN) { // 这里有个边界值需要注意
                n /= 2;
                x *= x;
            }
            x = 1 / x;
            n = -n;
        }
        double result = 1.0;
        while (n) { // 经典的快速幂算法
            if (n & 1) result *= x;
            n >>= 1;
            x *= x;
        }
        return result;
    }
};
int main() {
    Solution s;
    for (int i = -3; i < 10; ++i) {
        cout << s.myPow(2.0, i) << endl;
    }
    return 0;
}
