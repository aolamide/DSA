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
    map<int, int> inMap;
    TreeNode* helper(int start, int end, vector<int>& preorder, int pos = 0) {
        
        if(start > end) return nullptr;

        int val = preorder[pos];
        TreeNode *node = new TreeNode(val);
        
        int inPos = inMap[preorder[pos]];
        
        node->left = helper(start, inPos - 1, preorder, pos + 1);

        node->right = helper(inPos + 1, end, preorder, pos + inPos - start + 1);
        

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        };
        
        int l = 0;
        int r = preorder.size() - 1;

        return helper(l, r, preorder);
    }
};