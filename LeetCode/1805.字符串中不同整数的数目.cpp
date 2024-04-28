#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=1805 lang=cpp
 *
 * [1805] 字符串中不同整数的数目
 */

// @lc code=start
class Solution {
public:
    int numDifferentIntegers(string word) {
        std::vector<string> temp;
        int word_len = word.size();
        std::vector<int> index;
        std::vector<int> length;

        int i = 0;
        int len = 0;
        for(auto c : word){
            if(c >= '0' && c <= '9'){
                index.push_back(i);
                i++;
                len++;
                if(i == word_len){
                    if(len != 0) length.push_back(len);
                }
            }
            else if(c >= 'a' && c <= 'z'){
                word.replace(i, 1, " ");
                if(len != 0) length.push_back(len);
                len = 0;
                i++;  
            }
        } 
        
        int k = 0;
        for(int i = 0; i < length.size(); i++){
            temp.push_back(word.substr(index[k], length[i]));
            k += length[i];
        }
        
        
        return 0;
    }
};
// @lc code=end

