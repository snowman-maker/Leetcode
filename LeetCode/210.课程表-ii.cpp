/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> bfsMethod(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        // 将prerequisites存入有向图中，并记录入度
        for(const auto& info : prerequisites){
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }
        // 创建队列,将入度=0的课程加入队列
        queue<int> q;
        for(auto i=0; i<numCourses; i++){
            if(indeg[i] == 0) q.push(i);
        }
        //循环更新队列
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(int v : edges[u]){
                --indeg[v];
                if(indeg[v] == 0) q.push(v);
            }
        }
        if(result.size() == numCourses) return result;
        else return {};
    }
    void dfs(int u)
    {
        visited[u] = 1;
        for(int v: edges[u]){
            if(visited[u] == 0){
                dfs(v);
                if(!valid) return;
            }
            else if(visited[u] == 1){
                valid = false;
                return;
            }
        }
        visited[u] = 2;
        result.push_back(u);
    }
    vector<int> dfsMethod(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        // 将prerequisites存入有向图中
        for(const auto& info : prerequisites){
            edges[info[1]].push_back(info[0]);
        }
        for(int i=0; i<numCourses && valid; ++i){
            if(!visited[i]) dfs(i);
        }
        if(!valid) return {};
        reverse(result.begin(), result.end());
        return result;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        return bfsMethod(numCourses, prerequisites);
        // return dfsMethod(numCourses, prerequisites);
    }
private:
vector<vector<int>> edges; // 记录有向图
vector<int> indeg; // 记录入度
vector<int> visited; // 0->未搜索；1->搜索中；2->搜索完成
bool valid = true;
vector<int> result;
};
// @lc code=end

