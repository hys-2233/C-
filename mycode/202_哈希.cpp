#include <unordered_map>

// 快乐数的题

// 

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int, int> map;
        while(1) {
            
        }
    }
};