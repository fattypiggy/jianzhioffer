#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        long long copy_n = n;
        if (copy_n < 10) return copy_n;
        int order = 1;
        while (copy_n) {
            long long minus = order * (pow(10, order) - pow(10, order - 1));
            copy_n -= minus;
            if (order == 1) copy_n-=1;
            if (copy_n < 0) {
                copy_n += minus;
                break;
            }
            order++;
        }
        int shift = copy_n / order;
        int index = copy_n % order;
        int number = pow(10, order - 1) + shift;
        string str = to_string(number);
        int res = str[index] - '0';
//        if (res < 0) cout << "error:" << copy_n << endl;
        return res;
    }
};
int main() {
    Solution s;
    cout << s.findNthDigit(INT_MAX);
//    cout << s.findNthDigit(190) << endl;
    for (int i = 0; i < 1000; ++i) {
        cout << s.findNthDigit(i) << endl;
    }
    return 0;
}
