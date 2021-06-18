#include <iostream>
using namespace std;
/**
 * 使用DFS回溯法
 */
class Solution {
public:
    int movingCount(int m, int n, int k) {
        bool * visited = new bool[m * n];
        // 使用vector初始化二维数组
        // vector<vector<bool>> visited(m, vector<bool>(n, 0));
        memset(visited, 0, m * n);
        return dfs(0, 0, k, m, n, visited);
    }

private:
    int dfs(int i, int j, int k, int m, int n, bool* visited) {
        if (i >= m || i < 0 || j >= n || j < 0 || visited[i * n + j] == true || getSum(i) + getSum(j) > k)
            return 0;

        visited[i * n + j] = true;
        return 1 + dfs(i+1, j, k,m,n, visited) + dfs(i, j+1, k,m,n, visited);
    }

    int getSum(int number) {
        return number % 10 + number / 10;
    }
};
int main() {
    Solution s;
    cout << s.movingCount(3,2,17);
    return 0;
}
