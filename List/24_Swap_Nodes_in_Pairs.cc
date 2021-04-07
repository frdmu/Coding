// https://leetcode-cn.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *p = dummy, *q = p->next;

        while (q && q->next != NULL) {
            int tmp = p->next->val;
            p->next->val = q->next->val;
            q->next->val = tmp;
            p = q->next;
            q = p->next;
           
        }
        
        return dummy->next;
    }
};
