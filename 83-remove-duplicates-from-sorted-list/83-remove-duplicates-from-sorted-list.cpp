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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* currentNode = head, *headNode = head;
        head = head->next;
        while(head) {
            if(head->val != currentNode->val) {
                currentNode->next = head;
                currentNode = head;
            }
            head = head->next;
        };
        
        currentNode->next = nullptr;
        
        return headNode;
    }
};