/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
        // int left = 0, right = nums.size();
        // while (left < right) {
        //     if (nums[left] == val) {
        //         nums[left] = nums[right - 1];
        //         right--;
        //     } else {
        //         left++;
        //     }
        // }
        // return left;
    }
};
// @lc code=end

