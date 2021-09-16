#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string str;
        vector<string> v = splitString(s);
        for (int i = v.size() - 1; i >= 0; --i) {
            str.append(v[i]);
            if (i > 0)
                str.append(" ");
        }
        return str;
    }
private:
    vector<string> splitString(string s) {
        vector<string> v;
        int begin = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                end = i;
                if (s[begin] != ' ')
                    v.push_back(s.substr(begin, end - begin));
                begin = i;
            } else if (s[begin] != ' '){ // s[i] != ' ' && s[begin] != ' '
                if (i == s.size() - 1)
                    v.push_back(s.substr(begin, s.size() - begin)); // 最后一个字符是字母，所以需要结束
                continue;
            } else { // s[i] != ' ' && s[begin] == ' '
                begin = i;
                if (i == s.size() - 1)
                    v.push_back(s.substr(begin, 1)); // 最后一个字符是字母，倒数第二个是空格
            }
        }
        return v;
    }
};
int main() {
    Solution s;
    string str1 = "the sky is blue",
            str2 = "  hello world!  ",
            str3 = "a good   example",
            str4 = " 1";
    cout << s.reverseWords(str1) << endl
    << s.reverseWords(str2) << endl
    << s.reverseWords(str3) << endl
    << s.reverseWords(str4) << endl;
    return 0;
}
