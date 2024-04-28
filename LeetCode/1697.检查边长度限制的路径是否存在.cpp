/*
 * @lc app=leetcode.cn id=1697 lang=cpp
 *
 * [1697] 检查边长度限制的路径是否存在
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> res;
        int m = edgeList.size();
        for(int i = 0; i < m; i++){
            sort(edgeList[i].begin(), edgeList[i].end()-1);
        }
        sort(edgeList.begin(), edgeList.end());
        for(int i = 0; i < m; i++){
            for(int j = 0; j < edgeList[i].size(); j++){
                cout << edgeList[i][j];
            }
            cout << endl;
        }
        cout << endl;
        // 按照 limitj 从小到大对 queries 进行排序
        sort(queries.end()-1, queries.end());
        for(int k = 0; k < queries.size(); ++k){
           for(int j = 0; j < 3; j++){
                cout << queries[k][j];
            }
            cout << endl;
        }
        for(int k = 0; k < queries.size(); ++k){
            vector<vector<int>> temp;
            for(int i = 0; i < m; i++){
                if(queries[k][2] < edgeList[i][2]){
                    temp.push_back(edgeList[i]);
                }
            }
            if(temp.size() == 0) res.push_back(false);
        }
        return {};
    }
};
// @lc code=end

