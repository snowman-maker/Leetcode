/*
 * @lc app=leetcode.cn id=2594 lang=cpp
 *
 * [2594] 修车的最少时间
 */
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        // long long time_max = ranks[0]*cars*cars;
        // 可以避免爆long long
        long long time_max = LLONG_MAX/2;
        long long time_min = 1;
        while(time_min <= time_max){
            long long sum = 0;
            long long time = (time_max+time_min)>>1;
            for(auto &r:ranks){
                sum += sqrt(time/r);
            }
            if(sum >= cars) time_max = time-1;
            else time_min = time+1;
        }
        return time_min;
    }
};
// @lc code=end

