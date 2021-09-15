#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int *small = &nums[0], *large = &nums[nums.size() - 1];
        while (small < large) {
            if (*small + *large == target) // 最好用 target - *small == *large避免溢出
                break;
            else if (*small + *large < target) {
                small++;
            } else
                large--;
        }
        return {*small, *large};
    }
};
int main() {
    Solution s;
    vector<int> v{2, 7, 9, 15};
    int target = 16;
    vector<int> vector1 = s.twoSum(v, target);
    cout << vector1[0] << " " << vector1[1] << endl;
    return 0;
}
