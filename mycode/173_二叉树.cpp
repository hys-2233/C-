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
 
class BSTIterator {
private:
    void inorder(TreeNode* root, vector<int>& res);

    vector<int> inorderTraversal(TreeNode* root);

    vector<int> arr_;
    int index_;
public:
    BSTIterator(TreeNode* root): arr_(inorderTraversal(root)), index_(0) {
        
    }
    
    int next() {
        return arr_[index_++];
    }
    
    bool hasNext() {
        if (index_ < arr_.size()) {
            return true;
        }
        return false;
    }
};

vector<int> BSTIterator::inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}

void BSTIterator::inorder(TreeNode* root, vector<int>& res){
    if (root == nullptr) {
        return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */