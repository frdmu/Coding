// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
// solution: traversal
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
        int flag = 0; 
        
        while (p->next) {
            ListNode* q = p->next; 
            while (q->next != NULL && p->next->val == q->next->val) {
                q = q->next;
                flag = 1;
            }
            if (flag) {
                p->next = q->next;
                flag = 0;
            } else {
                p = p->next;
            }
        }

        return dummy->next;
    }
};
