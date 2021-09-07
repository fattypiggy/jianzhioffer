#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int sz = s.size();
        int dp[sz+1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i < sz + 1; ++i) {
            string substr = s.substr(i-2, 2);
            dp[i] = (substr >= "10" && substr <= "25") ? (dp[i-2] + dp[i-1]) : dp[i-1];
        }
        return dp[sz];
    }
};
int main() {
    Solution s;
    int n = 12258;
    cout << s.translateNum(n) << endl; // 5
    return 0;
}
