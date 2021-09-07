#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        // length[i]：以s[i]为结尾的最长不含重复字符的子串的长度
        int length[s.size()];
        length[0] = 1;
        int res = 1;
        for (int i = 1; i < s.size(); ++i) {
            int j = i - length[i-1]; // j从s[i-1]的头部开始，确保s[i-1]是不重复的。
            for (; j < i; ++j) {
                if (s[j] == s[i])
                    break;
            }
            if (j == i)
                length[i] = length[i-1] + 1;
            else
                length[i] = i - j;
            if (length[i] > res)
                res = length[i];
        }
        return res;
    }
};
int main() {
    Solution s;
    string str1 = "arabcacfr", str2 = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str1) << endl; // 4
    cout << s.lengthOfLongestSubstring(str2) << endl; // 3
    return 0;
}
