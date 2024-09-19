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
private:
    int result = 0;
    void dfs(Node* root, int count) {
        result = max(result, count);
        for(Node* child : root->children) {
            dfs(child, count + 1);
        }
    }
public:
    int maxDepth(Node* root) {
        if(root) dfs(root, 1);
        return result;
    }
};