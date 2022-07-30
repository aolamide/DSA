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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;

        ListNode *lessThan = new ListNode(0);
        ListNode *lessThanTail = lessThan;

        ListNode *greaterThanOrEqual = new ListNode(0);
        ListNode *greaterThanOrEqualTail = greaterThanOrEqual;

        while(head) {
            if(head->val < x) {
                lessThanTail->next = head;
                lessThanTail = lessThanTail->next;
            } else {
                greaterThanOrEqualTail->next = head;
                greaterThanOrEqualTail = greaterThanOrEqualTail->next;
            }
            head = head->next;
        }

        lessThanTail->next = greaterThanOrEqual->next;
        greaterThanOrEqualTail->next = nullptr;
        
        return lessThan->next;
    }
};