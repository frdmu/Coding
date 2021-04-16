// https://leetcode-cn.com/problems/linked-list-cycle-ii/
// solution: slow and fast pointer
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        // Judge whether there is a circle 
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        // there is a circle, the distance of (index1 - cycle begins) equals to  (index2 - cycle begins)
        ListNode* index1 = head;
        ListNode* index2 = fast->next;
        while (index1 != index2) {
            index1 = index1->next;
            index2 = index2->next;
        }
        return index1;
    }
};
