/*
 * @lc app=leetcode.cn id=1812 lang=cpp
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char word, num;
        word = coordinates[0];
        num = coordinates[1];
        cout << word << ", " << num << endl;
        int x, y;
        switch (word)
        {
        case 'a':
            x = 1;
            break;
        case 'b':
            x = 2;
            break;
        case 'c':
            x = 3;
            break;
        case 'd':
            x = 4;
            break;
        case 'e':
            x = 5;
            break;
        case 'f':
            x = 6;
            break;
        case 'g':
            x = 7;
            break;
        case 'h':
            x = 8;
            break;
        default:
            break;
        }

        switch (num)
        {
        case '1':
            y = 1;
            break;
        case '2':
            y = 2;
            break;
        case '3':
            y = 3;
            break;
        case '4':
            y = 4;
            break;
        case '5':
            y = 5;
            break;
        case '6':
            y = 6;
            break;
        case '7':
            y = 7;
            break;
        case '8':
            y = 8;
            break;
        default:
            break;
        }
        if(x % 2 == 0){
            if(y % 2 == 0) return false;
            else return true;
        }else{
            if(y % 2 == 0) return true;
            else return false;
        }
    }
};
// @lc code=end

