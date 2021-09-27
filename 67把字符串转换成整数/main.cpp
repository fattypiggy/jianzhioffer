#include <iostream>
using namespace std;
class Solution {
public:
    // 此题条件判断处极易出现错误
    int strToInt(string str) {
        if (str == "") return 0;
        long long num = 0;
        // flag: 用于存放符号位是否找到
        // isNegative: 数字的符号
        // started: 计算数字是否已经开始，若已经开始，不允许跳过空格
        bool flag = false, isNegative = false, started = false;
        for (int i = 0; i < str.size(); ++i) {
            char c = str[i];
            if (c >= '0' && c <= '9') {
                started = true; // 对应测试样例 "   +0 123"
                num = num * 10 + (c - '0');
                if (isNegative && -num < INT_MIN) {
                    num = INT_MIN;
                    break;
                } else if (!isNegative && num > INT_MAX) {
                    num = INT_MAX;
                    break;
                }
            }
            else if ((c == '+' || c == '-') && flag == false && started == false) {
                started = true; // 对应测试样例 "-   234"
                flag = true;
                if (c == '-') isNegative = true;
            }
            else if (c == ' ' && num == 0 && !started)
                continue;
            else
                break;
        }
        return isNegative ? -num : num;
    }
};
int main() {
    Solution s;
    string str1 = "42",
            str2 = "    -42",
            str3 = "4193 with words",
            str4 = "words and 987",
            str5 = "-91283472332",
            str6 = "91283472332",
            str7 = "   +0 123";
    cout << s.strToInt(str1) << endl
            << s.strToInt(str2) << endl
            << s.strToInt(str3) << endl
            << s.strToInt(str4) << endl
            << s.strToInt(str5) << endl
            << s.strToInt(str6) << endl
            << s.strToInt(str7) << endl;
    return 0;
}
