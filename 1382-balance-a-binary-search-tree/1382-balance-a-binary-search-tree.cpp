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
    void inorder(TreeNode* root, vector<TreeNode*> &v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    
    TreeNode* createBST(vector<TreeNode*> &v, int lo, int hi) {
        if (hi < lo) return NULL;
        
        int mid = lo + (hi - lo) / 2;
        TreeNode* root = v[mid];
        root->left = createBST(v, lo, mid-1);
        root->right = createBST(v, mid+1, hi);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root,v);
        return createBST(v, 0, v.size() - 1);
    }
};