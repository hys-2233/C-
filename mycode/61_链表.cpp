struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k==0) {
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        auto cur = head;
        int length = 0;
        while (cur != nullptr) {
            cur = cur->next;
            length++;
        }
        k = k%length;
        if (k == 0) return head;


        // 使用双指针
        ListNode* first = dummy;
        ListNode* second = dummy;
        for (int i = 0; i < k; i++) {
            first = first->next;
        }
        while (first->next != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        first->next = dummy->next;
        dummy->next = second->next;
        second->next = nullptr;
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};