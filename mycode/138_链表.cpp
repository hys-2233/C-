
// Definition for a Node.
#include <unordered_map>
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    std::unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // 复制链表 有一个问题，怎么让它指向新的节点呢

        // 可以递归，返回一个复制了的新的节点

        if (cachedNode.count(head)) {
            auto new_node = new Node(head->val);
            cachedNode[head] = new_node;
            new_node->next = copyRandomList(head->next);
            new_node->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};


