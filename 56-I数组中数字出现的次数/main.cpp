#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    /**
     * 用异或进行分类。
     * 出现两次的数字进行异或结果是0，所以nums数组进行异或的结果是两个只出现一次的数字进行异或的值。
     * 通过此函数findFirstDigitOf1去找到第一个是1的下标。因为第一个1是这两个只出现一次的数的显著区别。
     * @param nums 
     * @return 两个只出现一次的数字
     */
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        int number1 = 0, number2 = 0;
        int result = 0;
        for (int number: nums) {
            result ^= number;
        }
        int n = findFirstDigitOf1(result);
        int comparedNumber = pow(2, n-1);
        for (int number: nums) {
            if (number & comparedNumber)
                number1 ^= number;
            else
                number2 ^= number;
        }
        return {number1, number2};
    }
private:
    unsigned int findFirstDigitOf1(int result) {
        int index = 0;
        while (result > 0) {
            result = result >> 1;
            index++;
        }
        return index;
    }
};
int main() {
    Solution s;
    vector<int> v1{4,1,4,6}, v2{1,2,10,4,1,4,3,3}, v3{-1, -2, -2, -3, 4, 4}, v4{1, 2};
//    s.singleNumbers(v1); // {1, 6}
//    s.singleNumbers(v2); // {2, 10}
//    s.singleNumbers(v3); // {-1, -3}
    s.singleNumbers(v4); // {1, 2}
    return 0;
}
