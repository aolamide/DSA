/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(!root) return root;
//         queue<Node*> q;
        
//         q.push(root);
//         int level = 1;
        
//         while(!q.empty()) {
//             Node* curr = q.front();
//             q.pop();
//             if(curr->left) q.push(curr->left);
//             if(curr->right) q.push(curr->right);
            
//             level--;
//             if(level == 0) {
//                 level = q.size();
//             } else {
//                 curr->next = q.front();
//             }
//         }
        
//         return root;
//     }
// };

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        Node* curr = root;
        while(curr->left) {
            Node* c = curr;
            while(c) {
                c->left->next = c->right;
                if(c->next) c->right->next = c->next->left;
                c = c->next;
            }
            curr = curr->left;
        }
        
        return root;
    }
};