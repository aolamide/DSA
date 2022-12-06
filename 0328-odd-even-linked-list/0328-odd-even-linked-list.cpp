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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* even = head->next;
        ListNode* evenHead = even;
        ListNode* odd = head;
        ListNode* oddHead = odd;
        
        ListNode* curr = head->next->next;
        int i = 3;
        
        even->next = nullptr;
        odd->next = nullptr;
        
        while(curr) {
            ListNode* tmp = curr->next;
            if(i % 2 != 0) {
                //odd
                odd->next = curr;
                odd = curr;
                odd->next = nullptr;
            } else {
                //even
                even->next = curr;
                even = curr;
                even->next = nullptr;
            }
            
            curr = tmp;
            i++;
        }
        
        odd->next = evenHead;
        
        return oddHead;
        
    }
};