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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *curr = result;
        bool carry = false;
        
        while(l1 || l2) {
            int sum = 0;
            
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            
            if(carry) sum += 1;
            
            if(sum < 10) {
                curr->next = new ListNode(sum);
                carry = false;
            }
            
            else {
                curr->next = new ListNode(sum % 10);
                carry = true;
            }
            
            curr = curr->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(carry) curr->next = new ListNode(1);
        
        return result->next;
    }
};