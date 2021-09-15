#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int bits = sizeof(int) * 8;
        vector<int> v( bits, 0);
        for (int i = 0; i < nums.size(); ++i) {
            int mask = 1;
            int j = bits;
            while (--j) {
                if (nums[i] & mask)
                    v[j]++;
                mask = mask << 1;
            }

        }
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] % 3 != 0)
                res += pow(2, bits - 1 - i);
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> v{3};
    cout << s.singleNumber(v) << endl;
    return 0;
}
