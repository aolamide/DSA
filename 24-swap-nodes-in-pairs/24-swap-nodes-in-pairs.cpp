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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *prev = nullptr;
        ListNode *curr = head;
        
        while(curr && curr->next) {
            ListNode *tmp = curr->next;
            
            if(prev) prev->next = tmp;
            else head = tmp;
            
            curr->next = tmp->next;
            
            tmp->next = curr;
            
            
            prev = curr;
            curr = tmp->next->next;
        }
        
        return head;
    }
};