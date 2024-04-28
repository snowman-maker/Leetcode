/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int word[26] = {0};
        for(int i = 0; i < sentence.size(); i++){
            word[sentence[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(word[i] == 0) return false;
        }
        return true;
    }
};
// @lc code=end

