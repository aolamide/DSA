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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        
        int nodesCount = 0;
        ListNode *curr = head;
        while(curr) {
            nodesCount++;
            curr = curr->next;
        }
        
        int mid = nodesCount / 2;
        int i = 1;
        curr = head;
        while(i <= mid) {
            i++;
            curr = curr->next;
        }
        
        if(nodesCount % 2 != 0) curr = curr->next;
        ListNode *rev = nullptr;
        while(curr) {
            ListNode *tmp = curr->next;
            curr->next = rev;
            rev = curr;
            
            curr = tmp;
        }
        cout << rev->val << '\t' << head->val << endl;
        while(rev) {
            if(rev->val != head->val) return false;
            rev = rev->next;
            head = head->next;
        }
        
        return true;
        
    }
};

//thought process
//get count of nodes in list
//divide by two
//reverse the second half
//then compare the two halfs node by node