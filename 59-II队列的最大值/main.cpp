#include <iostream>
#include <queue>
#include <deque>
using namespace std;
class MaxQueue {
public:
    MaxQueue() {

    }

    int max_value() {
        return dq.empty() ? -1 : dq.front();
    }

    void push_back(int value) {
        que.push(value);
        while (!dq.empty() && value > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(value);
    }

    int pop_front() {
        if (que.empty()) {
            return -1;
        }
        int res = que.front();
        que.pop();
        if (res == dq.front()) {
            dq.pop_front();
        }
        return res;
    }
private:
    /**
     * 保存队列的值
     */
    queue<int> que;
    /**
     * 保存最大值的递减队列
     */
    deque<int> dq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
int main() {
    MaxQueue *obj = new MaxQueue();
    int param_1 = obj->max_value();
    obj->push_back(94);
    obj->push_back(16);
    obj->push_back(89);
    int param_3 = obj->pop_front();
    obj->push_back(22);
    int param_4 = obj->pop_front();
    cout << param_1 << " " << param_3 << " " << param_4 << endl;
    return 0;
}
