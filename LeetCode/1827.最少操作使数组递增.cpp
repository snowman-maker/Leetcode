/*
 * @lc app=leetcode.cn id=1827 lang=cpp
 *
 * [1827] 最少操作使数组递增
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        // int max_num;
        // int min_num;
        // max_num = max(nums[0], nums[nums.size()-1]);
        // min_num = min(nums[0], nums[nums.size()-1]);
        // cout << "max = " << max_num << endl;
        // cout << "min = " << max_num << endl;
        int n = nums.size();
        // cout << "size = " << n << endl;
        int operation = 0;
        for(int i = 1; i < n; ++i){
            if(nums[i-1] >= nums[i]){
                int diff = nums[i-1] - nums[i];
                operation = operation + (diff + 1);
                nums[i] += (diff + 1);
            }
        }
        return operation;
    }
};
// @lc code=end

