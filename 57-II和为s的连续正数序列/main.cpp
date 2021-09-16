#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int small = 1, large = 2, destination = (1 + target) / 2, curSum = small + large;
        while (small < destination) {
            if (curSum == target)
                addToVector(small, large);
            while (curSum > target && small < large) {
                curSum -= small;
                small++;
                if (curSum == target)
                    addToVector(small, large);
            }
            large++;
            curSum += large;
        }
        return vv;
    }
private:
    vector<vector<int>> vv;
    void addToVector(int small, int large) {
        vector<int> v;
        for (int i = small; i <= large; ++i) {
            v.push_back(i);
        }
        vv.push_back(v);
    }
};
int main() {
    Solution s;
    s.findContinuousSequence(9); // {{2,3,4}, {4,5}}
    return 0;
}
