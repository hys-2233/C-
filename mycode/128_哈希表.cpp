#include "head.hpp"
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int &num : nums) {
            num_set.insert(num);
        }

        int max = 0;
        for (auto &num : num_set) {
            int count_num = 0;
            int count_max = 0;
            if (!num_set.count(num - 1)) {
                // 找到第一个数
                count_num = num;
                while(num_set.count(count_num)) {
                    count_max++;
                    count_num++;
                }
            }
            max = std::max(max, count_max);
        }
        return max;
    }
};