#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) return n - 1;
        if (n % 3 == 0)
            return fastRemainder(3, n / 3);
        else if (n % 3 == 1)
            return (4 * fastRemainder(3, n / 3 - 1)) % mod;
        else
            return (2 * fastRemainder(3, n / 3)) % mod;
    }

private:
    int mod = 1e9 + 7;
    /**
     * 循环取余
     * @param x base底数
     * @param a index指数
     * @return 对mod(1e9+7)取余的结果
     */
    long getRemainder(int x, int a) {
        long rem = 1;
        while (a) {
            rem = (x * rem) % mod;
            a--;
        }
        return rem;
    }
    /**
     * 快速幂球余数
     * @param x base底数 参数类型一定要为long类型！！！！
     * @param a index指数
     * @return 对mod(1e9+7)取余的快速幂结果
     */
    long fastRemainder(long x, int a) {
        long rem = 1;
        while (a) {
            if (a % 2)
                rem = (rem * x) % mod;
            x = (x * x) % mod;
            a /= 2;
        }
        return rem;
    }
};
int main() {
    Solution s;
//    发现long和long long是一样的
//    cout << LONG_BIT << endl << LONG_MAX << endl;
//    cout << LONG_LONG_MAX << endl;
//    cout << INT_MAX << endl;
    cout << s.cuttingRope(120) << endl;
//    for (int i = 2; i < 90; ++i) {
//        cout << s.cuttingRope(i) << endl;
//    }
    return 0;
}
