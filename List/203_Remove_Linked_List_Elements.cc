// https://leetcode-cn.com/problems/remove-linked-list-elements/
// solution: dummy head node
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next != nullptr) {
            if (p->next->val != val) {
                p = p->next;
            } else {
                ListNode* tmp = p->next;
                p->next = tmp->next;
                delete tmp;
            }
        }     

        return dummy->next;
    }
};
