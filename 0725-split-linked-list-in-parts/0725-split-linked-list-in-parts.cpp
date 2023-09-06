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
private:
    int countNodes(ListNode* head) {
        int count = 0;
        while(head) {
            count++;
            head = head->next;
        }
        return count;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k);
        
        int nodesCount = countNodes(head);
        int setCount = nodesCount / k;
        int rems = nodesCount % k;
        if(nodesCount < k) rems = 0;

        for(int i = 0; i < k; i++) {
            result[i] = head;
            for(int j = 0; j < setCount - 1; j++) {
                head = head->next;
            }
            if(!head) break;
            if(rems) {
                head = head->next;
                rems--;
            } 
            ListNode* curr = head->next;;
            head->next = nullptr;
            head = curr;
        }
        
        return result;
    }
};