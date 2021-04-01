// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p, *q;
        ListNode *H = new ListNode();
        H->next = head;

        p = H;
        q = p;
        for (int i = 0; i < n; i++) {
            if (q->next != NULL) 
                q = q->next; 
        }   
        for (; q->next != NULL; p = p->next, q = q->next);
        if (p == q) return NULL; 
        if (p->next != 0) {
            q = p->next;
            q = q->next;
        } 
        p->next = q;
        head = H->next;
        delete H;
        
        return head; 
    }
};
