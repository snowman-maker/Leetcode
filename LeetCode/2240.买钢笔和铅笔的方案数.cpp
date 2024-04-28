/*
 * @lc app=leetcode.cn id=2240 lang=cpp
 *
 * [2240] 买钢笔和铅笔的方案数
 */
#include<vector>
// @lc code=start
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long cnt = 0;
        int max_buy = total/cost1;
        for(int i=0; i<=max_buy; i++){
            cnt += (total-i*cost1)/cost2+1;
        }
        return cnt;
    }
};
// @lc code=end

