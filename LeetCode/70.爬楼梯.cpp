/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int p = 0; // 爬1级台阶 f(x-1)
        int q = 0; // 爬2级台阶 f(x-2)
        int res = 1; // f(x)
        for(int i=0; i<n; i++){
            p = q;
            q = res;
            res = p+q;
        }
        return res;
    }
};
// @lc code=end

