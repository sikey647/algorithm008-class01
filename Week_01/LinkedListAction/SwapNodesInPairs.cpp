// Definition for singly-linked list.
    struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };
 
// 解法一：迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *pre = nullptr,*cur = head, *re = nullptr;
        head = head->next;
        while(cur) {
            re = cur->next;
            if(!re)
                break;
            cur->next = re->next;
            re->next = cur;
            if(pre)
                pre->next = re;
            pre = cur;
            cur = pre->next;
        }
        return head;
    }
};

// 解法二：递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *ret = head->next;
        head->next = swapPairs(ret->next);
        ret->next = head;
        return ret;
    }
};
