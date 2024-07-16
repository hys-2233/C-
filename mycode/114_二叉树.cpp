
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
        getList(root);
    }

    TreeNode* getList(TreeNode* root) {
        if(!root) return nullptr;
        if (!root->left&&!root->right) {
            return root;
        }
        auto right = root->right;
        
        // 返回根节点, 
        auto leftTail = getList(root->left);
        // 有可能左子树不存在，直接用右子树根
        if (leftTail) {
            root->right = root->left;
            root->left = nullptr;
            leftTail->right = right;
        }

        // 有可能右子树不存在，直接使用左子树根
        auto res = getList(right);
        return res ? res : leftTail;
    }
};