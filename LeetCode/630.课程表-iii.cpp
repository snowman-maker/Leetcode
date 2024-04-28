/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), 
            [](const auto& a, const auto& b) { return a[1] < b[1]; }
            );

        priority_queue<int> q;
        int total_time = 0;

        for(const auto& course: courses){
            int duration = course[0], lastday = course[1];
            if(total_time + duration <= lastday){
                total_time += duration;
                q.push(duration);
            }
            // 如果不可以学，检查已经选了的课程中有没有耗时更长的替换掉
            else if(!q.empty() && q.top() > duration){
                total_time -= q.top() - duration;
                q.pop();
                q.push(duration);
            }
        }
        return q.size();
    }
};
// @lc code=end

