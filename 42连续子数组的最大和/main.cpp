#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        dp.push_back(nums[0]);
        int res = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp.push_back(max(dp[i-1] + nums[i], nums[i]));
            res = max(dp[i], res);
        }
        return res;
    }
private:
    vector<int> dp;
};
int main() {
    Solution s;
    vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(v); // 6
    return 0;
}
