#include <iostream>
using namespace std;
// 递归根左右实现DFS

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void DFS(TreeNode* node) {
    if (node == NULL) return;
    cout << node->val << " "; // 访问节点
    DFS(node->left);          // 递归访问左子树
    DFS(node->right);         // 递归访问右子树
}

int main() {
    // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "DFS: ";
    DFS(root);
    cout << endl;

    return 0;
}