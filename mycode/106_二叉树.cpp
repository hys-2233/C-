#include <vector>
#include <unordered_map>
using namespace std;


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
    unordered_map<int, int> index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return buildTreeInPost(inorder, postorder, 0, n-1, 0, n-1);
    }
    
    TreeNode* buildTreeInPost(vector<int>& inorder, vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
        if (inorder_left > inorder_right) {
            return nullptr;
        }
        auto root = new TreeNode(postorder[postorder_right]);
        auto inorder_root_pos = index[root->val];
        auto size_of_right_tree = inorder_right - inorder_root_pos;
        root->left = buildTreeInPost(inorder, postorder, inorder_left, inorder_root_pos - 1, postorder_left, postorder_right - 1 - size_of_right_tree);
        root->right = buildTreeInPost(inorder, postorder, inorder_root_pos + 1, inorder_right, postorder_right - 1 - size_of_right_tree, postorder_right -1 );
        return root;
    }

};