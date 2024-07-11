#include <climits>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //删除排序链表中所有重复的值，也就是说只需要一个存储单元存储上一个的记忆
        //然后顺序去遍历
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;
        auto cur = head;
        
        while (cur != nullptr) {
            bool duplicate = false;
            while (cur->next != nullptr && cur->val == cur->next->val) {
                ListNode* nodeToDelete = cur->next;
                cur->next = cur->next->next;
                delete nodeToDelete;
                duplicate = true;
            }
            if (duplicate) {
                ListNode* nodeToDelete = cur;
                pre->next = cur->next;
                cur = cur->next;
                delete nodeToDelete;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};