/*
 * @lc app=leetcode.cn id=2275 lang=cpp
 *
 * [2275] 按位与结果大于零的最长组合
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        std::vector<int> Bit(24, 0);
        int res = 0;
        
        for(int num : candidates){
            for(int i = 0; i < 24; i++){
                if(num & (1<<i)){
                    Bit[i]++;
                }
            }
        }
        for(int i = 0; i < 24; i++){
            res = max(res,Bit[i]);
        }
        return res;
    }
};
// @lc code=end

