#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
/**
 * 不考虑大数
 */
class Solution {
public:
    vector<int> printNumbers(int n) {
        int end = pow(10, n);
        for (int i = 1; i < end; ++i) {
            nums.push_back(i);
        }
        return nums;
    }
private:
    vector<int> nums;
};
/**
 * 考虑大数，用自增的方式。
 */
class BigNumber {
public:
    vector<string> printNumbers(int n) {
        string start(1, '1'), end(n, '9');
        while (start.size() <= end.size() && start <= end) {
            _big_nums.push_back(start);
            increament(start);
        }
        return _big_nums;
    }
private:
    vector<string> _big_nums;
    // 大数自增算法
    void increament(string &start) {
        bool flag = 0;
        int last = start.size() - 1;
        int num = start[last] - '0';
        if (num < 9) {
            start[last] = num + 1 + '0';
        } else {
            flag = 1;
            start[last] = '0';
        }
        if (flag) {
            for (int i = last - 1; i >= 0; --i) {
                int tmp = start[i] - '0';
                if (tmp < 9) {
                    start[i] = tmp + 1 + '0';
                    return;
                } else {
                    start[i] = '0';
                    continue;
                }
            }
            start = "1" + start;
        }
    }
};
int main() {
    Solution s;
    BigNumber b;
    vector<string>v = b.printNumbers(3);
    for (string e: v) {
        cout << e << "\n";
    }
    return 0;
}
