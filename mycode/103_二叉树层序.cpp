#include "head.hpp"
#include <queue>
#include <vector>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { 
        deque<TreeNode*> treeQueue;
        // flag 判断从哪里出;
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        bool flag = false;
        
        treeQueue.push_back(root);
        while (!treeQueue.empty()) {
            flag = !flag;
            vector<int> floor;
            int n = treeQueue.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur;
                if (flag) {
                    cur = treeQueue.front();
                    treeQueue.pop_front();
                } else {
                    cur = treeQueue.back();
                    treeQueue.pop_back();
                }

                floor.push_back(cur->val);
                if (flag) {
                    if (cur->left) treeQueue.push_back(cur->left);
                    if (cur->right) treeQueue.push_back(cur->right);
                } else {
                    if (cur->right) treeQueue.push_front(cur->right);
                    if (cur->left) treeQueue.push_front(cur->left);
                }
            }
            result.push_back(floor);
        }
        return result;
    }
};