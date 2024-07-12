#include <vector>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         // 数组中是否存在数相等，且距离小于k;
//         if (nums.size() <= 1) {
//             return false;
//         }
//         // 遍历去寻找往后的k个值
//         for (int i = 0; i < nums.size(); i++){
//             if (i + k > nums.size()) {
//                 return false;
//             }
//             for (int j = i + 1; j < i + k + 1; j++) {
//                 if (nums[i] == nums[j]) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++) {
            if (num_map.find(nums[i]) != num_map.end() && i - num_map[nums[i]] <= k) {
                return true;
            }
            num_map[nums[i]] = i;
        }
        return false;
    }
};