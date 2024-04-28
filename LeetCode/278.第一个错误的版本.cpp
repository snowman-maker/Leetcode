/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        // 0(left), ..., mid-1, mid, mid+1, ..., n(right)
        while(left < right){
            int mid = (right-left)/2 + left;
            // 如果发现 mid 是错误的
            // 那么说明在 mid 之前就可能存在错误版本
            // 也可能 mid 就是第一个错误版本
            // 此时应当在左半区间([left, mid])进行搜索
            if(isBadVersion(mid)){
                right = mid;
            }else{
                // mid版本无问题
                // 那么出问题的版本只可能在mid之后
                // 此时应当在右半区间([mid+1, right])进行搜索
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

