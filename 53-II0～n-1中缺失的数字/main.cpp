#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
int main() {
    Solution s;
    vector<int> v1{0,1,2,3,4,5,6,7,9}, v2{0,1,2,4,5,6,7,8,9}, v3{0}, v4{1};
    cout << s.missingNumber(v1) << endl; // 8
    cout << s.missingNumber(v2) << endl; // 3
    cout << s.missingNumber(v3) << endl; // 1
    cout << s.missingNumber(v4) << endl; // 0
    return 0;
}
