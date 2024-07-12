#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        for (auto &s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(s);
        }
        vector<vector<string>> res;
        for (auto &pair : anagramMap) {
            res.push_back(pair.second);
        }
        return res;
    }
};