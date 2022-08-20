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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos = 2;
        int firstPoint = 0;
        int lastPoint = 0;
        int minDistance = INT_MAX;
        ListNode *prev = head;
        ListNode *curr = head->next;
        
        while(curr->next) {
            int val = curr->val;
            
            //critical point
            if((prev->val > val && curr->next->val > val) || (prev->val < val && curr->next->val < val)) {
                if(!firstPoint) {
                    firstPoint = pos;
                } else {
                    minDistance = min(minDistance, pos - lastPoint);
                }
                lastPoint = pos;
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }
        
        if(!firstPoint || firstPoint == lastPoint) return { -1, -1 };
        
        return { minDistance, lastPoint - firstPoint };
    }
};

//traverse list
//keep track of position of each node
//keep track of previous node
//compare previous node and next node to current node
//store if it is a critical point
//max distance is distance between first and last critical points
//keep track of previous critical point and use the position of next critical point to determine min distance.
//keep updating min distance