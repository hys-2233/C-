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
    int count = 0;
    int countNodes(TreeNode* root) {
        //可以考虑直接DFS去遍历，然后计数
        if (root == nullptr) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};