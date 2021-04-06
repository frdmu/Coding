// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
// solution: new a dummy node
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p = dummy;
        
        while (p->next != NULL) {
            ListNode* q = p->next; 
            if (q->next != NULL && p->next->val == q->next->val) {
                ListNode* tmp = q->next; 
                q->next = tmp->next;
            } else {
                p = p->next;
            }
        }

        return dummy->next;
    }
};
