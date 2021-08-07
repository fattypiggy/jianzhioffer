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
    /**
     * version2：保持奇数偶数相对顺序不变
     * @param nums 待排序数组
     * @return 排序后数组
     */
    vector<int> exchange2(vector<int>& nums) {
        if (nums.empty()) return nums;
        vector<int> res(nums.size());
        unsigned index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]&1)
                res[index++] = nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!(nums[i]&1))
                res[index++] = nums[i];
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> v{1,2,3,4,5};
    vector<int> res = s.exchange2(v);
    return 0;
}
