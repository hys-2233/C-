#include <boost/algorithm/string/split.hpp>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
// #include <boost/algorithm//string.hpp>
using namespace std;

/**
 * @brief       abba cat dog dog cat
 * 
 */


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        // boost::split(words, s, boost::is_any_of(" "));
        istringstream in(s);
        string word;
        while (in >> word) {
            words.push_back(word);
        }
        unordered_map<char, string> pattern2word;
        unordered_map<string, char> word2pattern;
        if (pattern.size() != words.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++) {
            if ((pattern2word.count(pattern[i]) && pattern2word[pattern[i]] != words[i]) || (word2pattern.count(words[i]) && word2pattern[words[i]] != pattern[i])) {
                return false;
            } else {
                pattern2word[pattern[i]] = words[i];
                word2pattern[words[i]] = pattern[i];
            }
        }
        return true;
    }
};