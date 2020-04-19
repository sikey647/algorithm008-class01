// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


// 解法一
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1; 
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// 解法二
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *l = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                l->next = l1;
                l1 = l1->next;
            } else {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
        }
        l->next = l1 ? l1 : l2;
        return head->next;
    }
};

// 解法二，简洁写法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *l = head;
        while (l1 && l2) {
            ListNode* &node = l1->val < l2->val ? l1 : l2;
            l = l->next = node;
            node = node->next;
        }
        l->next = l1 ? l1 : l2;
        return head->next;
    }
};