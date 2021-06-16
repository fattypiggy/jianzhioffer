#include <iostream>
#include <vector>
using namespace std;
int findRepeatNumber(vector<int>& nums) {
    int index = 0;
    while (index < nums.size()) {
        if (index == nums[index]) {
            index++;
        } else if (nums[index] != nums[nums[index]]) { // swap
            int tmp = nums[nums[index]];
            nums[nums[index]] = nums[index];
            nums[index] = tmp;
        } else {
            return nums[index];
        }
    }
}
int main() {
    vector<int> v{2,3,1,0,2,5,3};
    cout << findRepeatNumber(v) << endl;
    return 0;
}
