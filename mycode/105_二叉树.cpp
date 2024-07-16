#include <algorithm>
#include <unordered_map>
#include <vector>

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
    unordered_map<int, int> hash_inorder; 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 先划分，再构造
        // 构造一个映射 节点值对应位置
        auto n = inorder.size();
        for (int i = 0; i < n; i++) {
            hash_inorder[inorder[i]] = i;
        }

        return buildTreeFromTree(preorder, inorder, 0, n-1, 0);    
    }

    TreeNode* buildTreeFromTree(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right,  int inorder_left) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // 根据前序遍历的头节点创建根节节点
        auto root = new TreeNode(preorder[preorder_left]);
        
        auto inorder_root_pos = hash_inorder[preorder[preorder_left]];
        
        // 得到左子树的大小
        auto size_of_left_tree = inorder_root_pos - inorder_left;
        
        root->left = buildTreeFromTree(preorder, inorder, preorder_left + 1, preorder_left+size_of_left_tree, inorder_left);
        root->right = buildTreeFromTree(preorder, inorder, preorder_left + 1 + size_of_left_tree, preorder_right, inorder_left + 1 + size_of_left_tree);
        return root;
    }

};


