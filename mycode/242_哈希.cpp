#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        if (s.size() != t.size()) {
            return false;
        }
        for (auto c: s) {
            map[c]++;
        }
        for (auto c: t) {
            if (map[c]-- == 0) {
                return false;
            }
        }
        return true;
    }

    bool isAnagramS(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return t == s;
    }
};

