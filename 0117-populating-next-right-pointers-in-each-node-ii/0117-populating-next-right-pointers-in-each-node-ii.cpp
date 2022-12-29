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

class Solution {
private:
    void solve(Node* root){
        if(!root) return;
        
        Node* near_left = NULL, *curr = root->next;
        
        while(curr){
            if(curr->left) {near_left = curr->left; break;}
            if(curr->right) {near_left = curr->right; break;}
            curr = curr->next;
        }
        
        if(root->left) root->left->next = root->right ? root->right : near_left;
        if(root->right) root->right->next = near_left;
        
        solve(root->right);
        solve(root->left);
    }
public:
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};