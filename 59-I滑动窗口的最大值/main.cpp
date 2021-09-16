#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        vector<int> v;
        deque<int> dq; // 存放的是nums中数字的下标
        for (int i = 0; i < k; ++i) {
            // 始终保持dq.front是最大的值，dq.back()是下一个第二大的值。
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        for (int i = k; i < nums.size(); ++i) {
            v.push_back(nums[dq.front()]);
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            // 注意：如果最大的值已经不在滑动中，应pop_front()
            if (!dq.empty() && dq.front() <= (int)(i - k))
                dq.pop_front();
            dq.push_back(i);
        }
        v.push_back(nums[dq.front()]); // 最后留在dq中的值应该加进来。
        return v;
    }
};
int main() {
    Solution s;
    vector<int> v{4,3,11};
    int k = 3;
    s.maxSlidingWindow(v, k);
    return 0;
}
