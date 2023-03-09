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
        if(!head) return head;
        
        ListNode *tortoise = head, *hare = head;
        
        while(true) {
            hare = hare->next;
            tortoise = tortoise->next;
            
            if(!hare || !hare->next) {
                return nullptr;
            }
            
            hare = hare->next;
            
            if(hare == tortoise) break;
        }
        
        ListNode *start = head;
        
        while(start != hare) {
            start = start->next;
            hare = hare->next;
        }
        
        return hare;
    }
};