#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == res)
                count++;
            else
                count--;
            if (count == 0) {
                res = nums[i];
                count = 1;
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> v{1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << s.majorityElement(v);
    return 0;
}
