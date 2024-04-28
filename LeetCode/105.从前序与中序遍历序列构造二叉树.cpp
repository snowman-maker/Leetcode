/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

#include <cstddef>
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void preOrder(TreeNode *root) {
        if (root == nullptr) return;
        // 访问优先级：根节点-> 左子树-> 右子树
        vec.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(TreeNode* root){
        if(root == nullptr) return;
        // 访问优先级：左子树-> 根节点-> 右子树
        inOrder(root->left);
        vec.push_back(root->val);
        inOrder(root->right);
    }

    void postOrder(TreeNode* root){
        if(root == nullptr) return;
        // 访问优先级：左子树-> 右子树-> 根节点
        postOrder(root->left);
        postOrder(root->right);
        vec.push_back(root->val);
    }

    TreeNode* recursiveBuild(const vector<int>& preorder, 
                            const vector<int>& inorder, 
                            int pre_left, int pre_right, int in_left, int in_right)
    {
        if(pre_left > pre_right) return nullptr;
        int pre_root = pre_left;
        int in_root = index[preorder[pre_root]];

        TreeNode* root = new TreeNode(preorder[pre_root]);

        int left_subtree_size = in_root - in_left;
        root->left = recursiveBuild(preorder, inorder, pre_left+1, pre_left+left_subtree_size, in_left, in_root-1);
        root->right = recursiveBuild(preorder, inorder, pre_left+left_subtree_size+1, pre_right, in_root+1, in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size_ = preorder.size();
        for(int i=0; i<size_; i++){
            index[preorder[i]] = i;
        }
        return recursiveBuild(preorder, inorder, 0, size_-1, 0, size_-1);
    }
private:
    vector<int> vec;
    unordered_map<int, int> index;
    int size_;
};
// @lc code=end

