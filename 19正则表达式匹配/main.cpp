#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 返回string s和pattern是否匹配
     * @param s 待匹配字符串
     * @param p pattern
     * @return true/false
     */
    bool isMatch(string s, string p) {
        unsigned int s_size = s.size();
        unsigned int p_size = p.size();
        vector<vector<bool>> matrix(s_size + 1, vector<bool>(p_size + 1, false));
        for (int i = 0; i <= s_size; ++i) {
            for (int j = 0; j <= p_size; ++j) {
                // pattern size equals to zero
                if (j == 0) {
                    // if s.size == 0, matrix[0][0] == true, else matrix[i][0] == false.
                   matrix[i][j] = (i == 0);
                } else {
                    // the last char is '*'
                    if (p[j-1] == '*') {
                        // 这里两个if都会运算
                        if (j>=2)
                            matrix[i][j] = matrix[i][j-2];
                        if (i>=1 && j>=2 &&(s[i-1] == p[j-2] || p[j-2] == '.')) {
                            // 注意使用 ｜=
                            matrix[i][j] = (matrix[i][j] | matrix[i-1][j]);
                        }
                    } else { // the last char is dot or alpha
                        if (i>0 && (s[i-1] == p[j-1] || p[j-1] == '.'))
                            matrix[i][j] = matrix[i-1][j-1];
                    }
                }
            }
        }
        return matrix[s_size][p_size];
    }
};
int main() {
    Solution s;

    cout << s.isMatch("aa", "a") << "\n";
    cout << s.isMatch("aa", "a*") << "\n";
    cout << s.isMatch("ab", ".*") << "\n";
    cout << s.isMatch("aab", "c*a*b") << "\n";
    cout << s.isMatch("mississippi", "mis*is*p*.") << "\n";
    return 0;
}
