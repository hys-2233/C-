#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /**
         * @brief       tool
         *  判断两个字符串是否是异构字符串
         *  bool IsAnagram(s, m)
         */
        // 有几种字符串就分几种

        vector<vector<string>> res;
        for (auto s: strs) {
            if (res.empty()) {
                vector<string> tmp{s};
                res.push_back(tmp);
            } else {
                bool isNew = false;
                for (int i = 0; i < res.size(); i++) {
                    if (isAnagram(res[i][0], s)) {
                        res[i].push_back(s);
                        isNew = true;
                    }
                }
                if (!isNew) {
                    vector<string> tmp{s};
                    res.push_back(tmp);
                }
            }
            // 在res中找每个组的第一个来判断是否是异构
        }
        return res;
    }
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
};