#include <iostream>

// 定义二叉树节点
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 后序遍历函数
void postOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // 遍历左子树
    postOrder(root->left);

    // 遍历右子树
    postOrder(root->right);

    // 处理当前节点
    std::cout << "Node Value: "<< root->data << " ";
}

int main() {
    // 创建一个二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Post-order traversal: ";
    postOrder(root);

    return 0;
}
