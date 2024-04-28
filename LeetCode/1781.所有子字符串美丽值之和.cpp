/*
 * @lc app=leetcode.cn id=1781 lang=cpp
 *
 * [1781] 所有子字符串美丽值之和
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        // 遍历整个s
        // 计算每个子串的美丽值
        for(int i=0; i<n-2; ++i){
            for(int j=i+2; j<n; ++j){
                int max_freq = 0, min_freq = n; // 记录出现频率最高和最低的字符
                // 计算子串中字符相对'a'的偏移量
                // 间接计算了每个字符出现的频率
                int word[26] = {0}; // 0->25 ~ a->z

                // 子串[i,j]:s[i], s[i+1], ..., s[j]
                for(int k = i; k <= j; k++){
                    word[s[k] - 'a']++;
                    max_freq = max(max_freq, word[s[k] - 'a']);
                }

                for(int m=0; m < 26; m++){
                    if(word[m] > 0) min_freq = min(min_freq, word[m]);
                }

                int diff = max_freq - min_freq;
                res += diff;
            }
        }
        return res; 
    }
};
// @lc code=end

