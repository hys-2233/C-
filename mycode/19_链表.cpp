
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* first = dummyNode;
        ListNode* second = dummyNode;
        // 使用双指针的办法处理这个问题

        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        while (first->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummyNode->next;
        delete dummyNode;
        return newHead;
    }
};