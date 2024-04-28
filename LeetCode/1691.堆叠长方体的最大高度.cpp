/*
 * @lc app=leetcode.cn id=1691 lang=cpp
 *
 * [1691] 堆叠长方体的最大高度
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int cube_nums = cuboids.size();
        // 对每一个 Cube 的长宽高进行从小到大的排序
        for(int i = 0; i < cube_nums; i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        // 针对 cuboids 按照第一个元素大小进行排序
        // 放置的顺序：短对短，中对中，长对长
        sort(cuboids.begin(), cuboids.end());
        for(auto cube : cuboids){
            for(auto i : cube){
                cout << i << " ";
            }
            cout << endl;
        }
        /* eg.
          Input: [[50,45,20],
                  [95,37,53],
                  [45,23,12]]
         Output: [[12,23,45],
                  [20,45,50],
                  [37,53,95]]
         */
        int f[cube_nums]; // 记录寻找到的有效的堆叠方式所能到达的最高高度
        for(int i = 0; i < cube_nums; i++){
            f[i] = 0;
            // 寻找能满足堆叠条件的方块
            for(int j = 0; j < i; j++){
                // 排序后 cuboids[j][0] <= cuboids[i][0] 恒成立
                if(cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]){
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += cuboids[i][2];
        }

        return *max_element(f, f + cube_nums);
    }
};
// @lc code=end

