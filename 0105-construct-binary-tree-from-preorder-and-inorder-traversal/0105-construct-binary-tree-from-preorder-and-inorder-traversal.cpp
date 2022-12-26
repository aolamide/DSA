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
    int pIdx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        return buildTree(preorder, 0, preorder.size() - 1);
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, int start, int end) {
        
        if(start > end) return nullptr;
        
        int val = preorder[pIdx++];
        
        int mid = inMap[val];
        
        TreeNode* root = new TreeNode(val);
        
        root->left = buildTree(preorder, start, mid - 1);
        
        root->right = buildTree(preorder, mid + 1, end);
        
        return root;
        
    }
};