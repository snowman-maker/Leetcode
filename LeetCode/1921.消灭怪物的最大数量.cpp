/*
 * @lc app=leetcode.cn id=1921 lang=cpp
 *
 * [1921] 消灭怪物的最大数量
 */
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> arrive_time(dist.size());
        for(int i=0; i<dist.size(); i++){
            arrive_time[i] = ceil(float((dist[i]))/speed[i]);
        }
        sort(arrive_time.begin(), arrive_time.end());

        for(int i=0; i<dist.size(); i++){
            if(arrive_time[i] <= i){
                return i;
            }
        }
        return dist.size();
    }
};
// @lc code=end

