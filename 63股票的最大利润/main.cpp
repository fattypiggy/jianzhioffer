#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int min = prices[0];
        int profit = prices[1] - prices[0];
        for (int i = 2; i < prices.size(); ++i) {
            if (prices[i-1] < min)
                min = prices[i-1];
            profit = max(prices[i] - min, profit);
        }
        return profit > 0 ? profit : 0;
    }
};
int main() {
    Solution s;
    vector<int> v{7,1,5,3,6,4};
    cout << s.maxProfit(v) << endl;
    return 0;
}
