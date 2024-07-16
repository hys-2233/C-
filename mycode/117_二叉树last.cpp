#include <cinttypes>
#include <queue>
#include <iostream>
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        // 因为是一层一层查找，所以说，我可以直接使用层序遍历
        if (!root) return nullptr;
        std::queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            auto n = queue.size();
            Node* last = nullptr;
            for (int i = 0; i < n; i++) {
                Node* cur = queue.front();
                queue.pop();
                if (cur->left) {
                    queue.push(cur->left);
                }
                if (cur->right) {
                    queue.push(cur->right);
                }
                if (i != 0) {
                    last->next = cur;
                }
                last = cur;
            }
        }
        return root;
    }
};