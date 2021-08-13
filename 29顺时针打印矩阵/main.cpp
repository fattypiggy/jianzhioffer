#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};

        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        vector<int> v;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                v.push_back(matrix[top][i]);
            }
            for (int i = top+1; i <= bottom; ++i) {
                v.push_back(matrix[i][right]);
            }
            // 注意边界
            if (left < right && top < bottom) {
                for (int i = right-1; i > left; --i) {
                    v.push_back(matrix[bottom][i]);
                }
                for (int i = bottom; i > top; --i) {
                    v.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return v;
    }
};
int main() {
    vector<vector<int>> v1 = {{1,2,3,4},
                             {14,15,16,5},
                             {13,20,17,6},
                             {12,19,18,7},
                             {11,10,9,8}};
    vector<vector<int>> v2 = {{1}, {2}, {3}, {4}};
    vector<vector<int>> v3 = {{1}};
    vector<vector<int>> v4 = {{1,2,3},
                              {8,9,4},
                              {7,6,5}};
    Solution s;
    s.spiralOrder(v4);
    return 0;
}
