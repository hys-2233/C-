#include <algorithm>
#include <climits>

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
    int min_val = INT_MAX;
    int pre = -1;
    int getMinimumDifference(TreeNode* root) {
        //二叉搜索树只需要中序列遍历就可以
        //DFS
        dfs(root);
        return min_val;
    }

    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root->left);
        if(pre != -1) {
            min_val=std::min(min_val, root->val - pre);
        }
        pre = root->val;
        dfs(root->right);
    }
};