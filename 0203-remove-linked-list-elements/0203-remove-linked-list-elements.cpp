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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* headPtr = nullptr;

        //find first non-val node
        while(head && head->val == val) {
            head = head->next;
        }

        if(!head) return nullptr;


        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;  // Skip val node
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};