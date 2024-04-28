/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 *
 * [2582] 递枕头
 */

// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time) {
        // int remainder = time % (n-1);
        // int consult = time / (n-1);
        // if(remainder == 0 && consult % 2 == 0) return 1;
        // if(remainder == 0 && consult % 2 != 0) return n;
        // else if(consult % 2 == 0) return 1+remainder;
        // else return n-remainder;
        time %= (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
    }
};
// @lc code=end

