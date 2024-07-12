struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto dummy1 = new ListNode(-1);
        auto dummy2 = new ListNode(-1);
        auto less = dummy1;
        auto greater = dummy2;
        
        auto cur = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                less->next = cur;
                less = less->next;
            } else {
                greater->next = cur;
                greater = greater->next;
            }
            cur = cur->next;
        }

        greater->next = nullptr;
        less->next = dummy2->next;
        
        auto newHead = dummy1->next;
        delete dummy2;
        delete dummy1;
        return newHead;
    }
};