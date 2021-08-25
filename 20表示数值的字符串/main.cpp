#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    /**
     * 表示数值的字符串遵循模式A[.[B]][e|EC]或者.B[e|EC]，其中A为数值的整数部分，B为紧跟着小数点的小数部分，C为紧跟着e或E的指数部分。
     * 其中A和C是可以包含+-符号的，B不可以包含+-符号
     * @param s
     * @return
     */
    bool isNumber(string s) {
        if (s.empty()) return false;
        int index = 0;
        while (s[index] == ' ')
            index++;
        bool numeric = isInteger(s, index);
        if (s[index] == '.') {
            ++index;
            // 用||的原因
            // 1. 小数可以没有整数部分，.1 == 0.1
            // 2. 小数点后面可以没有数字 123. == 123.0
            // 3. 小数点前后都可以有数字
            numeric = isUnsignedInteger(s, index) || numeric;
        }
        if (s[index] == 'e' || s[index] == 'E') {
            ++index;
            // 用&&的原因
            // 1. e前面必须有数字，错误实例.e1, e1
            // 2. e后面必须有整数，错误实例12e, 12e5.4
            numeric = numeric && isInteger(s, index);
        }
        while (s[index] == ' ')
            index++;
        return numeric && (index == s.size());
    }

private:
    bool isInteger(string s, int& index) {
        if (s[index] == '+' || s[index] == '-')
            index++;
        return isUnsignedInteger(s, index);
    }
    bool isUnsignedInteger(string s, int& index) {
        const int i = index;
        while (index < s.size() && s[index] >= '0' && s[index] <= '9')
            index++;
        return index > i;
    }
};
int main() {
    string string1 = "+100", string2 = "0", string3 = "e", string4 = "    .4   ", string5 = "3.";
    Solution s;
    cout << s.isNumber(string1); // true
    cout << s.isNumber(string2); // true
    cout << s.isNumber(string3); // false
    cout << s.isNumber(string4); // true
    cout << s.isNumber(string5); // true
    return 0;
}
