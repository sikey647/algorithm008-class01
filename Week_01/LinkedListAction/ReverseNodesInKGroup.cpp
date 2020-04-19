
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode *pre = nullptr, *cur = head, *re = nullptr;
        while(cur != tail) {
            re = cur->next;
            cur->next = pre;
            pre = cur;
            cur = re;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tail = head;
        int cnt = k;
        while(cnt--) {
            if(!tail)
                return head;
            tail = tail->next;
        }

        ListNode *newHead = reverseList(head, tail);
        head->next = reverseKGroup(tail, k);

        return newHead;
    }
};