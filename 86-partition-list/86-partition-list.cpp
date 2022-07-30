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

        ListNode *greaterThan = new ListNode(0);
        ListNode *greaterThanTail = greaterThan;

        while(head) {
            if(head->val < x) {
                lessThanTail->next = head;
                lessThanTail = lessThanTail->next;
            } else {
                greaterThanTail->next = head;
                greaterThanTail = greaterThanTail->next;
            }
            head = head->next;
        }

        lessThanTail->next = greaterThan->next;
        greaterThanTail->next = nullptr;
        
        return lessThan->next;
    }
};