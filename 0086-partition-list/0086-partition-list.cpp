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
        ListNode* sent = new ListNode(0);
        ListNode* sentTail = sent;
        
        
        ListNode* currHead = nullptr;
        ListNode* currHold = nullptr;
        
        while(head) {
            ListNode* tmp = head->next;
            if(head->val < x) {
                sentTail->next = head;
                sentTail = head;
                
                sentTail->next = nullptr;
            } else {
                if(!currHead) {
                    currHead = head;
                } 
                if(!currHold) {
                    currHold = head;
                } else {
                    currHold->next = head;
                    currHold = currHold->next;
                }
            }
            
            head = tmp;
        }
        
        if(currHead) currHold->next = nullptr;
        
        sentTail->next = currHead;
        
        return sent->next;
    }
};