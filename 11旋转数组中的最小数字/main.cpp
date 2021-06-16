#include <iostream>
#include <vector>
using namespace std;
int minInOrder(vector<int>& numbers);
int minArray(vector<int>& numbers) {
    int start = 0, end = numbers.size() - 1;
    int mid = start;
    while (numbers[start] >= numbers[end]) {
        if (end - start == 1) {
            mid = end;
            break;
        }
        mid = start + (end - start) / 2;
        if (numbers[start] == numbers[end] && numbers[start] == numbers[mid])
            return minInOrder(numbers);
        if (numbers[mid] >= numbers[start])
            start = mid;
        else if (numbers[mid] <= numbers[end])
            end = mid;
    }
    return numbers[mid];
}
int minInOrder(vector<int>& numbers) {
    int result = numbers[0];
    for (int i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < result)
            result = numbers[i];
    }
    return result;
}
int main() {
    vector<int> v{1, 3, 5, 0};
    cout << minArray(v) << endl;
    return 0;
}
