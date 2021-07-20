#include <vector>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int prev = 0, last = nums.size() - 1;
        while (last > prev) {
            if (nums[prev] & 1) {
                prev++;
                continue;
            }
            if (!(nums[last] & 1)) {
                last--;
                continue;
            }
            swap(nums[prev], nums[last]);
            prev++;
            last--;
        }
        return nums;
    }
};
int main() {
    Solution s;
    vector<int> v{1,2,3,4,5};
    s.exchange(v);
    return 0;
}
