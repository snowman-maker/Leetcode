/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void findDeepestNode(TreeNode* root, int depth, int& maxDepth)
    {
        if(root == nullptr) return;
        if(depth > maxDepth){
            maxDepth = depth;
        }
        findDeepestNode(root->left, depth+1, maxDepth);
        findDeepestNode(root->right, depth+1, maxDepth);
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        // return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        int depth = 0;
        int maxDepth = 0;
        findDeepestNode(root, depth, maxDepth);
        return maxDepth+1;
    }
};
// @lc code=end

