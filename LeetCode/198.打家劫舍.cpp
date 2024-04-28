/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int rob1(vector<int>& nums){
        // f(k) 表示从前 k 个房子中能偷到的最大金额
        // 偷前 k-1 间房子  或者  偷前 k-2 间房子和最后一间房子
        if(nums.size() == 0) return 0;
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int k=2; k<=n; k++){
            dp[k] = max(dp[k-1], dp[k-2]+nums[k-1]);
        }
        return dp[n];
    }
    
    int rob2(vector<int>& nums){
        int prev = 0;
        int curr = 0;
        // 每次循环，计算“偷到当前房子为止的最大金额”
        for (int i : nums) {
            // 循环开始时，curr 表示 dp[k-1]，prev 表示 dp[k-2]
            // dp[k] = max{ dp[k-1], dp[k-2] + i }
            int temp = max(curr, prev + i);
            prev = curr;
            curr = temp;
            // 循环结束时，curr 表示 dp[k]，prev 表示 dp[k-1]
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        // return rob1(nums);
        return rob2(nums);
    }
};
// @lc code=end

