#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 可以在grid上直接更改，省去dp的空间。
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid);
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                if (j-1 >= 0)
                    dp[i][j] = max(grid[i][j] + dp[i][j-1], dp[i][j]);
                if (i-1 >= 0)
                    dp[i][j] = max(grid[i][j] + dp[i-1][j], dp[i][j]);
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};
int main() {
    Solution s;
    vector<vector<int>> grid{
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    cout << s.maxValue(grid) << endl;
    return 0;
}
