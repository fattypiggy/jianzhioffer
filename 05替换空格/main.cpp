#include <iostream>
#include <string>
using namespace std;
string replaceSpace(string s) {
    int count = 0, len = s.size();
    for (auto i: s) {
        if (i == ' ')
            count++;
    }
    s.resize(len + count * 2);
    for (int i = s.size() - 1, j = len - 1; i >= 0, j>= 0 ; --i, --j) {
        if (s[j] == ' ') {
            s[i] = '0';
            s[--i] = '2';
            s[--i] = '%';
        } else
            s[i] = s[j];
    }
    return s;
}
int main() {
    string s = "We are happy.";
    std::cout << replaceSpace(s) << std::endl;
    return 0;
}
