
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if (head == nullptr) {
//             return nullptr;
//         }
//         auto dammyNode = new ListNode();
//         dammyNode->next = head;
//         // 将需要翻转的链表剥离出来
//         while (left-- != 1) {
//             dammyNode = dammyNode->next;
//         }
//         ListNode* pre = dammyNode;
//         dammyNode = dammyNode->next;
//         ListNode* cur = dammyNode;
            
//         right = right - left;
//         while (right-- != 1) {
//             dammyNode = dammyNode->next;
//         }
//         ListNode* end = dammyNode;
//         dammyNode = dammyNode->next;
//         end ->next = nullptr;
//         ListNode* after = dammyNode;
        
//         auto new_head = reverseList(cur, nullptr);
//         pre->next = new_head;
//         while (new_head != nullptr) {
//             new_head = new_head->next;
//         }
//         new_head = after;
//         return head;
//     }

//     ListNode* reverseList(ListNode* cur, ListNode* pre) {
//         auto tmp = cur->next;
//         cur->next = pre;
//         if (tmp == nullptr) {
//             return cur;
//         }
//         return reverseList(cur, pre);
//     }
// };


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;

        // Move `pre` to the node before the `left`-th node
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        ListNode* cur = pre->next;
        ListNode* next = nullptr;

        // Reverse the sublist from `left` to `right`
        for (int i = 0; i < right - left; ++i) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};