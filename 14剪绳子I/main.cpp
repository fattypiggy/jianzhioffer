#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) return n - 1; // 不加这一行会出现addressSanitizer: heap-buffer-overflow on address错误
        vector<int> dp(n+1); // dp[i]: 长度为i的绳子乘积最大值
        // 起初dp数组当作数字用来做乘法
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i = 4; i <= n; ++i) {
            int max = 0;
            for (int j = 1; j <= i/2; ++j) {
                int product = dp[j] * dp[i-j];
                if (product > max)
                    max = product;
            }
            dp[i] = max;
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    // Leetcode给出的n的范围[2,58].
    for (int i = 2; i < 59; ++i) {
        cout <<"dp["<<i<<"]: "<< s.cuttingRope(i) << endl;
    }
    return 0;
}
