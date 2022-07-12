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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* tailLeft = nullptr; //to store node at (left - 1)
        int position = 1;
        
        while(position < left) {
            tailLeft = curr;
            curr = curr->next;
            position++;
        }
        
        ListNode* revTail = curr; //store node at (left)
        
        //reverse list from left to right
        ListNode* rev = nullptr;
        while(position <= right) {
            ListNode* nextTmp = curr->next;
            curr->next = rev;
            rev = curr;
            curr = nextTmp;
            position++;
        }
        
        if(tailLeft) tailLeft->next = rev; //point node (left - 1) to node (n)
        revTail->next = curr; //point node (left) to node (right+1)
        
        
        //if m is 1, return the head of the reversed portion
        if(left == 1) return rev;
        return head;
    }
};