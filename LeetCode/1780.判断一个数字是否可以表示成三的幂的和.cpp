/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkPowersOfThree(int n) {
        // 3^0 ~ 3^15
        // 题目转换成是否存在一个组合在3^0 ~ 3^15中
        vector<int> choose;
        for(int i =0; i < 16; i++) choose.push_back(pow(3, i));

        // 如果 n = pow(3, x)
        for(int i = 0; i < 16; i++){
            if(n == choose[i]) return true;
        }

        int index = 0;
        vector<int> temp = choose;
        while(n != 0 && n > 0){
            for(int i =0; i < temp.size(); i++){
                // 遍历choose数组，在其中找到一个和 n 最接近的数，并找到下标
                if(n >= temp[i]) index = i;
            }
            n -= temp[index];
            temp.erase(temp.begin() + index);
            if(n == 0) return true;
            index = 0;
        } 
        return false;
    }
};
// @lc code=end

