/*
 * @lc app=leetcode.cn id=2605 lang=cpp
 *
 * [2605] 从两个数字数组里生成最小数字
 */
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int> set1;
        for(int i : nums1){
            set1.insert(i);
        }
        for(int i : nums2){
            if(set1.find(i) != set1.end()){
                return i;
            }
        }
        return min(nums1[0], nums2[0])*10+max(nums1[0], nums2[0]);
    }
};
// @lc code=end

