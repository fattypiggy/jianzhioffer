#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        s.push(-1);
        int j = 0;
        for (int i = 0; i < popped.size(); ++i) {
            if (popped[i] != s.top()) {
                for (; j < pushed.size(); ++j) {
                    if (popped[i] == pushed[j]) {
                        ++j;
                        break;
                    }
                    else
                        s.push(pushed[j]);
                }
            } else {
                s.pop();
                continue;
            }
        }

        return s.size() == 1;
    }
};
int main() {
    vector<int> v1{1,2,3,4,5};
    vector<int> v2{4,5,3,2,1};
    vector<int> v3{4,3,5,1,2};
    Solution s;
    cout << s.validateStackSequences(v1, v2); // expected: 1
    cout << s.validateStackSequences(v1, v3); // expected: 0
    return 0;
}
