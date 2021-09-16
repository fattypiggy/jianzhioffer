#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.size() - n).append(s.substr(0, n));
    }
};
int main() {
    Solution s;
    string str = "abcdef";
    int n = 2;
    cout << s.reverseLeftWords(str, n) << endl;
    return 0;
}
