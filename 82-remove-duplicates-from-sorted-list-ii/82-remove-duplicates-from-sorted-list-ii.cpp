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
        ListNode *newHead = nullptr, *tail = nullptr;
        
        int count = 1;
        ListNode *currNode = head;
        
        while(head->next) {
            head = head->next;
            if(head->val == currNode->val) count++;
            else {
                if(count == 1) {
                    if(!newHead) {
                        newHead = currNode;
                        tail = currNode;
                        newHead->next = tail;
                        tail->next = nullptr;
                    } else {
                        currNode->next = nullptr;
                        tail->next = currNode;
                        tail = currNode;
                    }
                }
                count = 1;
                currNode = head;
            }
        }
        if(count == 1) {
            if(!newHead) return head;
            head->next = nullptr;
            tail->next = head;
        }
        return newHead;
        
    }
};


//THOUGHT PROCESS
    
//init newhead as null
// init tail as null
//loop nodes
//start from head, keep a count = 1;
//keep current node = curr;
//if(head->next->val == curr->val) increase count
//else 
    //if count is >1, 
    //if(count == 1 and newHead is null) set newHead = curr, and tail = curr; 
    //if(count == 1 and newHead not null) tail->next = curr;
    //set count = 1 and curr = current node;
//return newHead

