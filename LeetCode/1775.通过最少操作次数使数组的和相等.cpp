/*
 * @lc app=leetcode.cn id=1775 lang=cpp
 *
 * [1775] 通过最少操作次数使数组的和相等
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int sum1 = 0, sum2 = 0;
        vector<int> small;
        vector<int> big;

        if(m*6 < n || n*6 < m) return -1;

        for(int i : nums1) sum1 += i;
        for(int i : nums2) sum2 += i;
        int diff = abs(sum1 - sum2);
        if(diff == 0) return 0;
        cout << diff << endl;
        big = (sum1 < sum2) ? nums2 : nums1;
        small = (sum1 < sum2) ? nums1 : nums2;
        // 用于存储跨度和出现次数
        // range[x] = y --> 跨度x出现了y次
        vector<int> range(6);
        // 小数组中的数变大
        for(auto i : small) range[6-i]++;
        // 大数组中的数变小
        for(auto i : big) range[i-1]++;

        // 核心思想是让差值diff越来越小
        for(int i = 5; i >= 0; i--){
            cout << "range[" << i << "] = " << range[i] << endl;
        }

        int result = 0;
        for (int i = 5; i >= 0; i--){
            while(range[i] > 0){
                result++;
                if(i >= diff) return result;
                range[i]--;
                diff -= i;
            }
        }

        return -1;
    }
};
// @lc code=end

