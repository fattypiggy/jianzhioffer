#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    // k <= arr.size()
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty() || k == 0) return {};
        for (auto e: arr) {
            if (priorityQueue.size() < k) {
                priorityQueue.push(e);
            } else if (e < priorityQueue.top()) {
                    priorityQueue.push(e);
                    priorityQueue.pop();
            }
        }
        vector<int> v;
        while (!priorityQueue.empty()) {
            v.push_back(priorityQueue.top());
            priorityQueue.pop();
        }
        return v;
    }

private:
    priority_queue<int, vector<int>, less<int>> priorityQueue;
};
int main() {
    vector<int> arr{0,0,0,1,1,1};
    int k = 4;
    Solution s;
    s.getLeastNumbers(arr, k);
    return 0;
}
