#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        _min.push(INT_MAX);
    }

    void push(int x) {
        _s.push(x);
        _min.push(std::min(_s.top(), _min.top()));
    }

    void pop() {
        _s.pop();
        _min.pop();
    }

    int top() {
        return _s.top();
    }

    int min() {
        return _min.top();
    }
private:
    stack<int> _s;
    stack<int> _min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->min();
    obj->pop();
    cout << obj->top();
    cout << obj->min();
    return 0;
}
