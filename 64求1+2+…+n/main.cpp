#include <iostream>
using namespace std;
class Calculator {
public:
    Calculator() {
        N++;
        sum += N;
    }
    static void reset() {
        N = 0;
        sum = 0;
    }
    static unsigned int GetSum() {
        return sum;
    }
private:
    static unsigned int N;
    static unsigned int sum;
};
// 静态成员一定要在类的外部初始化，否则默认为0。
unsigned int Calculator::sum = 0;
unsigned int Calculator::N = 0;
class Solution {
public:
    int sumNums(int n) {
        // 若没有reset，静态成员将持续保留。
        Calculator::reset();
        Calculator *temp = new Calculator[n];
        return Calculator::GetSum();
    }
};

int main() {
    Solution s;
    cout << s.sumNums(5) << endl;
    return 0;
}
