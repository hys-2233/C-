#include "head.hpp"
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> history_char;
        int max = 0; int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (history_char.count(s[i]) && history_char[s[i]] >= start) {
                start = history_char[s[i]] + 1;
            }
            history_char[s[i]] = i;
            max = max > (i - start + 1) ? max : (i - start + 1);
        }
        return max;
    }
};