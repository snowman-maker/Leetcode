/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        edges.resize(numCourses); // 记录有向图
        indeg.resize(numCourses); // 记录入度
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        for(auto& info: prerequisites){
            edges[info[0]].push_back(info[1]);
            ++indeg[info[1]];
        }
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(indeg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto& v:edges[u]){
                isPre[u][v] = true;
                for(int i=0; i<numCourses; ++i) isPre[i][v] = isPre[i][v] | isPre[i][u];
                --indeg[v];
                if(indeg[v] == 0) q.push(v);
            }
        }
        vector<bool> res;
        for(auto query: queries) res.push_back(isPre[query[0]][query[1]]);
        return res;
    }
private:
vector<vector<int>> edges;
vector<int> indeg;

};
// @lc code=end

