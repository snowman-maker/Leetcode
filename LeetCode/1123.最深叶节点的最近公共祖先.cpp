/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
#include <vector>
#include <iostream>
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    // void findDepestNode(TreeNode* root, int depth, int& maxDepth, TreeNode*& deepestNode){
    //     if(root == nullptr) return;
    //     if(depth > maxDepth){
    //         maxDepth = depth;
    //         deepestNode = root;
    //     }
    //     findDepestNode(root->left, depth+1, maxDepth, deepestNode);
    //     findDepestNode(root->right, depth+1, maxDepth, deepestNode);
    // }
    // TreeNode* findParentNode(TreeNode* root, TreeNode* target, TreeNode*& parent){
    //     if(root == nullptr) return nullptr;
    //     if(root->left == target || root->right == target){
    //         parent = root;
    //         return parent;
    //     }
    //     if(findParentNode(root->left, target, parent) || findParentNode(root->right, target, parent)){
    //         return parent;
    //     }
    //     return nullptr;
    // }
    int mh = -1;
    TreeNode *result = nullptr;
    int dfs(TreeNode *node, int h) {
        if( !node ) return h-1;
        int left = dfs(node->left, h+1);
        int right = dfs(node->right, h+1);
        if( left == right && left >= mh ) {
            mh = left;
            result = node;
        }
        return max(left, right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // int maxDepth = 0;
        // TreeNode* deepestNode = nullptr;
        // findDepestNode(root, 0, maxDepth, deepestNode);
        // std::cout << maxDepth << std::endl;
        // TreeNode* parent = nullptr;
        // auto res = findParentNode(root, deepestNode, parent);
        // return res;
        dfs(root, 0);
        return result;
    }
};
// @lc code=end

