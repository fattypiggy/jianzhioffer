#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 妈的直接用STL做多香！
    int search(vector<int>& nums, int target) {
        auto [l, r] = equal_range(nums.begin(), nums.end(), target);
        return distance(l, r);
    }
};
int main() {
    Solution s;
    vector<int> v1{1,2,5,5,5,6,7}, v2{1}, v3{1,2,5,5,5,6,7};
    cout << s.search(v1, 5) << endl; // 3
    cout << s.search(v2, 1) << endl; // 1
    cout << s.search(v2, 5) << endl; // 0
    cout << s.search(v3, 15) << endl; // 0
    return 0;
}
