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
        if (!root) return nullptr;
        std::queue<Node*> queue;
        std::vector<Node*> list_node;
        queue.push(root);
        while (!queue.empty()) {
            auto n = queue.size();
            for (int i = 0; i < n; i++) {
                Node* cur = queue.front();
                list_node.push_back(cur);
                queue.pop();
                if (cur->left) {
                    queue.push(cur->left);
                }
                if (cur->right) {
                    queue.push(cur->right);
                }
            }
            for (auto it = list_node.begin(); it != list_node.end(); it++) {
                if (it + 1 != list_node.end()) {
                    (*it)->next = *(it + 1);
                } else {
                    (*it)->next = nullptr;
                }
            }
            list_node.clear();
        }
        return root;
    }
};