#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 用数组的方式比map效率更高
    char firstUniqChar(string s) {
        vector<int> v(26);
        for (int i = 0; i < s.size(); ++i) {
            v[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (v[s[i] - 'a'] == 1)
                return s[i];
        }
        return ' ';
    }
};
int main() {
    Solution s;
    string str = "abcab";
    cout << s.firstUniqChar(str) << endl;
    return 0;
}
