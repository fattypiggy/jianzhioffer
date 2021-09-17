#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int min_n = 14, max_n = -1;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) continue;
            if (m[nums[i]]++ != 0)
                return false;
            min_n = min(nums[i], min_n);
            max_n = max(nums[i], max_n);
        }
        // 即使全是0，也是对的。
        return max_n - min_n <= 4;
    }
};
int main() {
    Solution s;
    vector<int> v1{1,2,3,4,5}, v2{1,2,3,0,0}, v3{1,3,5,6,0}, v4{0,0,1,0,0};
    cout << s.isStraight(v1) << endl
         << s.isStraight(v2) << endl
         << s.isStraight(v3) << endl
         << s.isStraight(v4) << endl;
    return 0;
}
