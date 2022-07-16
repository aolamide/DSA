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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode *sentinel, *curr;
        sentinel = new ListNode();
        curr = sentinel;
        
        while(list1 && list2) {
            // cout << list1->val << " " << list2->val << endl;
            if(list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
             curr = curr->next;
        }
        
        if(list1) curr->next = list1;
        if(list2) curr->next = list2;
        
        return sentinel->next;
    }
};

// thought process
// init sentinel and set curr as sentinel
//loop through both lists, append l1 to curr if it lower and l2 to curr if l2 is lower.
//move curr to curr->next;
//append whichever list still has values to curr
//return sentinel->next