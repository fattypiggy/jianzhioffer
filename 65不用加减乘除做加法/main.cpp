#include <iostream>
class Solution {
public:
    int add(int a, int b) {
        int sum, carry;
        do {
            sum = a ^ b;
            // c++不支持负数移位，需要转换成unsigned
            carry = (unsigned)(a & b) << 1; // 进位
            a = sum;
            b = carry;
        } while (b != 0);
        return sum;
    }
};
int main() {
    Solution s;
    std::cout << s.add(-1, -2) << std::endl;
    return 0;
}
