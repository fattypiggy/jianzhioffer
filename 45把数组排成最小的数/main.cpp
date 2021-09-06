#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> v_str;
        string res;
        for (int num: nums)
            v_str.push_back(to_string(num));
        sort(v_str.begin(), v_str.end(), compare);
        for (string str: v_str) {
            res.append(str);
        }
        return res;
    }
    static bool compare(string &s1, string &s2) {
        string str1 = s1 + s2;
        string str2 = s2 + s1;
        return str1 < str2;
    }
};
int main() {
    Solution s;
    vector<int> nums{1, 10, 12, 116};
    cout << s.minNumber(nums) << endl;
    return 0;
}
