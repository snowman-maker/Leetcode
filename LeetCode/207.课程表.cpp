/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for(const auto& info : prerequisites){
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> que;
        for(int i = 0; i < numCourses; ++i){
            if(indeg[i] == 0) que.push(i);
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();
            result++;
            for(int v : edges[u]){
                --indeg[v];
                if(indeg[v] == 0) que.push(v);
            }
        }
        if(result == numCourses) return true;
        else return false;
    }
private:
vector<vector<int>> edges; // 记录有向图
vector<int> indeg; // 记录入度
int result;
};
// @lc code=end

