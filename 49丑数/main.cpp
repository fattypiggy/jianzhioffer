#include <iostream>
using namespace std;
class Solution {
public:
    // 只包含质数因子2、3、5的数称为丑数，例如，6，8。14包含因子7，所以不是丑数。
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        int *pUglyNumbers = new int[n];
        pUglyNumbers[0] = 1;
        int count = 1;
        int *pMultiple2 = pUglyNumbers; // 指向首个x2后大于当前丑数的丑数
        int *pMultiple3 = pUglyNumbers; // 指向首个x3后大于当前丑数的丑数
        int *pMultiple5 = pUglyNumbers; // 指向首个x5后大于当前丑数的丑数
        while (count < n) {
            int num = min(*pMultiple2 * 2, *pMultiple3 * 3, *pMultiple5 * 5);
            pUglyNumbers[count] = num;
            while (*pMultiple2 * 2 <= num)
                pMultiple2++;
            while (*pMultiple3 * 3 <= num)
                pMultiple3++;
            while (*pMultiple5 * 5 <= num)
                pMultiple5++;
            count++;
        }
        int res = pUglyNumbers[n-1];
        delete []pUglyNumbers;
        return res;
    }
private:
    int min(int a, int b, int c) {
        int min = a;
        if (b < min)
            min = b;
        if (c < min)
            min = c;
        return min;
    }
};
int main() {
    Solution s;
    for (int i = 1; i <= 10; ++i) {
        cout << s.nthUglyNumber(i) << endl;
    }
    return 0;
}
