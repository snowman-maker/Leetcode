/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int flag = 1;
        if(flag == 0){
            for(int i = 0; i < nums2.size(); i++){
            nums1[i+m] = nums2[i];
            }
            sort(nums1.begin(), nums1.end());
        }
        else if (flag == 1)
        {
            int p1 = m-1, p2 = n-1;
            int current;
            int tail = m+n-1;
            while(p1 >= 0 || p2 >= 0){
                if(p1 == -1){
                    current = nums2[p2--];
                }
                else if (p2 == -1)
                {
                    current = nums1[p1--];
                }
                else if(nums1[p1] > nums2[p2]){
                    current = nums1[p1--];
                }
                else{
                    current = nums2[p2--];
                }
                nums1[tail--] = current;
            }
        }
        


    }
};
// @lc code=end

