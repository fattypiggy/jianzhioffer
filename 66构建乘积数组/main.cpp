#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int sz = a.size();
        if (sz < 0) return {};
        // c[i]为 a[0]*...*a[i-1]的结果
        // d[i]为 a[i+1]*...*a[n-1]的结果
        // res[i] = c[i] * d[i]
        vector<int> c(sz, 1), d(sz, 1), res(sz, 1);
        for (int i = 1; i < sz; ++i) {
            c[i] = a[i-1] * c[i-1];
            d[sz-i-1] = a[sz-i] * d[sz-i];
        }
        for (int i = 0; i < sz; ++i) {
            res[i] = c[i] * d[i];
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> v{0};
    s.constructArr(v);
    return 0;
}
