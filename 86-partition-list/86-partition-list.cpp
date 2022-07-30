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
        if(!head || !head->next) return head;

        ListNode *currNode = head;
        ListNode *tmp;

        ListNode *lessThan = new ListNode(0);
        ListNode *lessThanTail = lessThan;

        ListNode *greaterThan = new ListNode(0);
        ListNode *greaterThanTail = greaterThan;

        while(currNode) {
            tmp = currNode->next;
            currNode->next = nullptr;

            if(currNode->val < x) {
                lessThanTail->next = currNode;
                lessThanTail = lessThanTail->next;
            } else {
                greaterThanTail->next = currNode;
                greaterThanTail = greaterThanTail->next;
            }

            currNode = tmp;
        }

        lessThanTail->next = greaterThan->next;

        return lessThan->next;
    }
};