/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int right = n - 1;
        int left = 0;
        int mid = 0;
        if(target > nums[n-1]) return n;
        else if(target < nums[0]) return 0;
        while(left <= right){
            mid = (right - left) / 2 + left;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
        }
        // 如果在数组中没有找到 target
        // 那么最终：
        // right->比target小的数
        // left->比target大的数
        // 那么target就应该插入left所指的位置
        return left;
    }
};
// @lc code=end

