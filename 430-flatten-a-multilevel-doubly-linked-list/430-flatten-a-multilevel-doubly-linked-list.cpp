/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        
        Node *curr = head;
        
        while(curr->next || curr->child) {
            if(curr->child) {
                Node *childTail = curr->child;
                
                while(childTail->next) {
                    childTail = childTail->next;
                }
                
                if(curr->next) curr->next->prev = childTail;
                childTail->next = curr->next;
                
                curr->child->prev = curr;
                curr->next = curr->child;
                
                curr->child = nullptr;
            }
            curr = curr->next;
        }
        
        return head;
    }
};



//idea
//Merger from top to bottom.

//thought process
    //loop through first level, if current node has no child, move to next
        //else if curr node has a child, get the tail of the child list.
        //Then point tail to curr->next, point curr->next->prev to child tail
        //point the prev of the child head to curr, point curr->next to the child head
        //finally point curr->child to null
    //Continue traversal until end of list, that is, when you reach a node that has no child and no next.