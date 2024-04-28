/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        int cnt = 0;
        int temp = -1;
        for(int i=0; i<N; i++){
            if(flowerbed[i] == 1){
                if(temp < 0) cnt += i/2;
                else cnt += (i-temp-2)/2;
                temp = i;
            }
        }
        if (temp < 0) cnt += (N + 1)/2;
        else cnt += (N - temp - 1) / 2;
        return cnt >= n;
    }
};
// @lc code=end

