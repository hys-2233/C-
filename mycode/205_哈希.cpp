#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        int relation[256] = {};
        int relation_reverse[256] = {};
        // 遍历s字符串，如果当前字符不在relation中，那么就将t中的字符加入到relation中
        for (int i = 0; i < s.size(); i++) {
            if (relation[s[i]] == 0 && relation_reverse[t[i]] == 0) {
                relation[s[i]] = t[i];
                relation_reverse[t[i]] = s[i];
            } else {
                if (relation[s[i]] != t[i] || relation_reverse[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
