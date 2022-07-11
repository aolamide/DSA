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
    ListNode* reverseList(ListNode* head) {
        //initialize the tail of the reversed list
        ListNode* rev = nullptr;
        
        ListNode* nextTmp;
        while(head) {
            nextTmp = head->next; //store next value temporarily
            head->next = rev; //set next to the reverse head
            rev = head; //update reverse head
            head = nextTmp; //move head to next node
        }
        
        return rev;
    }
};