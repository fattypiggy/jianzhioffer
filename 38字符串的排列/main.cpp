#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<string> permutation(string s) {
        permutation(s, 0);
        return v;
    }
private:
    vector<string> v;
    // 把s分为两部分，固定头，后面为交换部分
    void permutation(string &s, int index) {
        if (index == s.size()) {
            v.push_back(s);
            return;
        }
        set<char> set_char;
        for (int i = index; i < s.size(); ++i) {
            // 剪枝
            if (set_char.find(s[i]) != set_char.end()) continue;
            else set_char.insert(s[i]);
            swap(s[index], s[i]);
            permutation(s, index + 1);
            swap(s[index], s[i]);
        }
    }
};
int main() {
    Solution s;
    string str = "aabc";
    s.permutation(str);
    return 0;
}
