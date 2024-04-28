/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int k=0; k<n; k++){
                if(coins[k] <= i){
                    dp[i] = min(dp[i], dp[i-coins[k]]+1);
                }
            }
        }
        return dp[amount] > amount ? -1: dp[amount];
    }
};
// @lc code=end

