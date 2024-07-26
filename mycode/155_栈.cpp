#include "head.hpp"
#include <algorithm>

class MinStack {
private:
vector<int> stack;
vector<int> min_stack;

public:
// 需要常数时间内找到最小值，则需要一个排序
    MinStack() {

    }
    
    void push(int val) {
        stack.push_back(val);
        if (min_stack.empty() || min_stack.back() >= val) {
            min_stack.push_back(val);
        }
    }
    
    void pop() {
        int val = stack.back();
        stack.pop_back();
        if (val == min_stack.back()) {
            min_stack.pop_back();
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_stack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */