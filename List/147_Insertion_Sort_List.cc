// https://leetcode-cn.com/problems/insertion-sort-list/
// #1.solution: create another qhead list
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
 /*
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* phead = new ListNode();
        ListNode* qhead = new ListNode();
        qhead->next = head;
        head = head->next;
        phead->next = head;
        qhead->next->next = NULL;
        
        while (phead->next != NULL) {
            int tmp = phead->next->val;
            ListNode* p = phead->next;
            phead->next = p->next;
            ListNode* q = qhead;
            while (q->next != NULL && q->next->val < tmp) {
                q = q->next;
            }
            p->next = q->next;
            q->next = p;                
        }

        return qhead->next;
    }
};
*/

// #2.solution: manipulate in original list 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* phead = new ListNode(), *lastSorted, *cur;
        phead->next = head;
        lastSorted = phead;
        cur = head;

        while (cur->next != NULL) {
            if (cur->next->val >= lastSorted->next->val) {
                lastSorted = cur;
                cur = cur->next;
            } else {
                ListNode* q = cur->next; 
                cur->next = q->next;
                ListNode* p = phead;
                while(p != cur && p->next->val < q->val) {
                    p = p->next;
                }
                q->next = p->next;
                p->next = q;
                while (lastSorted->next != cur) {
                    lastSorted = lastSorted->next;
                }
            }
        }
        
        return phead->next;
    }
};
