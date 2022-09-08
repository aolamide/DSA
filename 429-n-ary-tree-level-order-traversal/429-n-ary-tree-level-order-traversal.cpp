/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> result;
        
        queue<Node*> q;
        q.push(root);
        int levelCount = 1;
        vector<int> tmp;
        
        while(!q.empty()) {
            Node* curr = q.front();
            tmp.push_back(curr->val);
            
            q.pop();
            
            for(auto c : curr->children) {
                q.push(c);
            }
            
            levelCount--;
            
            if(levelCount == 0) {
                result.push_back(tmp);
                levelCount = q.size();
                tmp = {};
            }
        }
        
        return result;
    }
};