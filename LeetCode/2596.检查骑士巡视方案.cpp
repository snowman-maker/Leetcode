/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 *
 * [2596] 检查骑士巡视方案
 */
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<vector<int>> validStep(grid.size()*grid.size(), vector<int>(2));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                validStep[grid[i][j]][0] = i;
                validStep[grid[i][j]][1] = j;
            }
        }
        if(grid[0][0] != 0) return false;
        for(int i=0; i<grid.size()*grid.size()-1; ++i){
            if(abs(validStep[i][0] - validStep[i+1][0])*abs(validStep[i][1] - validStep[i+1][1]) != 2){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

