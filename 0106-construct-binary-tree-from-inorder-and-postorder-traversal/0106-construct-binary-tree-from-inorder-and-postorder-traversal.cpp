/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> inMap;
    int pIdx;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        pIdx = postorder.size() - 1;
        
        return buildTree(postorder, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& postorder, int start, int end) {
        
        if(start > end) return nullptr;
        
        int val = postorder[pIdx--];
        
        int mid = inMap[val];
        
        TreeNode* root = new TreeNode(val);
        
        root->right = buildTree(postorder, mid + 1, end);
        
        root->left = buildTree(postorder, start, mid - 1);
        
        
        
        return root;
        
    }
};