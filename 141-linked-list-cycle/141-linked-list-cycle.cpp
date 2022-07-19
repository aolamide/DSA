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
    bool hasCycle(ListNode *head) {
        if(!head) return head;
        
        ListNode *tortoise = head, *hare = head;
        
        while(true) {
            hare = hare->next;
            tortoise = tortoise->next;
            
            if(!hare || !hare->next) {
                return false;
            }
            
            hare = hare->next;
            
            if(hare == tortoise) break;
        }
        
        return true;
    }
};

//Floyd tortoise and hare algorithm