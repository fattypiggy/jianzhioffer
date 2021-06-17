#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool findPath(vector<vector<char>>& board, string word, int& index, int rows, int cols, int row, int col, bool * visited);
/**
 * 回溯法
 * @param board
 * @param word
 * @return
 */
bool exist(vector<vector<char>>& board, string word) {
    int index = 0;
    int rows = board.size(), cols = board[0].size();
    bool *visited = new bool[rows*cols];
    memset(visited, 0, rows*cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (findPath(board, word, index, rows, cols, i, j, visited)) return true;
        }
    }
    delete[] visited;
    return false;
}
bool findPath(vector<vector<char>>& board, string word, int& index, int rows, int cols, int row, int col, bool* visited) {
    if (word[index] == '\0')
        return true;
    bool hasPath = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == word[index] && !visited[row * cols + col]) {
        ++index;
        visited[row * cols + col] = true;

        hasPath = findPath(board, word, index, rows, cols, row+1, col, visited)
                || findPath(board, word, index, rows, cols, row, col+1, visited)
                || findPath(board, word, index, rows, cols, row-1, col, visited)
                || findPath(board, word, index, rows, cols, row, col-1, visited);
        if (!hasPath) {
            --index;
            visited[row * cols + col] = false;
        }
    }
    return hasPath;
}
int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << exist(board, word) << endl;
    return 0;
}
