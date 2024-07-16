
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                // 找到左子树中的最右节点
                TreeNode* rightmost = curr->left;
                while (rightmost->right) {
                    rightmost = rightmost->right;
                }
                // 重新连接右子树
                rightmost->right = curr->right;
                // 将左子树移到右边
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // 移动到下一个节点
            curr = curr->right;
        }
    }
};