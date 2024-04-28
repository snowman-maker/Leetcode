/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int right = size - 1;
        int left = 0;
        // 划分为 left mid right
        // 判断 target 是否和 nums[mid] 相同
        // nums[0](left), ..., nums[mid-1], nums[mid], nums[mid+1], ... nums[size - 1](right)
        while(left <= right){
            int mid = (right - left) / 2 + left;
            if(nums[mid] == target) return mid;
            // 在右半边寻找目标数[mid+1, right]
            else if(nums[mid] < target) left = mid + 1;
            // 在左半边寻找目标数[left, mid-1]
            else if(nums[mid] > target) right = mid - 1;
        }
        return -1;
    }
};
// @lc code=end

