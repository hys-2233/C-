#include "head.hpp"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 遇到数，压入栈
        // 遇到操作符号，出栈a, b, 并将结果压入栈
        stack<int> stk;
        for (auto &token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                if (token == "+") stk.push(a + b);
                else if (token == "-") stk.push(b - a);
                else if (token == "*") stk.push(a * b);
                else stk.push(b / a);
            }
            else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};