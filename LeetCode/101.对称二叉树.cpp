/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <queue>

class Solution {
public:
    bool treeCheck(TreeNode* leftTree, TreeNode* RightTree)
    {
        if(!(leftTree == nullptr) && !(RightTree == nullptr)) return true; 
        else if(!leftTree || !RightTree) return false;
        return leftTree->val == RightTree->val && treeCheck(leftTree->left, RightTree->right) && treeCheck(leftTree->right, RightTree->left);
    }
    
    bool iterateCheck(TreeNode* LeftTree, TreeNode* RightTree)
    {
        std::queue<TreeNode*> q;
        q.push(LeftTree);
        q.push(RightTree);
        while(!q.empty()){
            LeftTree = q.front(); 
            q.pop();
            RightTree = q.front();
            q.pop();
            if(!LeftTree && !RightTree) continue;
            if((!LeftTree || !RightTree) || (LeftTree->val != RightTree->val)) return false;

            q.push(LeftTree->left);
            q.push(RightTree->right);

            q.push(LeftTree->right);
            q.push(RightTree->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        // return treeCheck(root, root);
        return iterateCheck(root->left, root->right);
    }
};
// @lc code=end

