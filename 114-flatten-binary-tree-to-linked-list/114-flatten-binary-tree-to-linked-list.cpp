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
    
    TreeNode* rightEndNode(TreeNode* root){
        if (!root->right) return root;
        return rightEndNode(root->right);
    }
    
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* tmpRight;
        TreeNode* rightEnd;
        
        while (root){
            if (root->left){
                rightEnd = rightEndNode(root->left);
                tmpRight = root->right;
                root->right = root->left;
                root->left = nullptr;
                rightEnd->right = tmpRight;
            }
            root=root->right;
        }
    }
};

//thought process
//for each node, if it has a left node, get the
//right most leaf of the left subtree. append the right node to the root,
//append null to the left of the root.
//then append the right node to the rightmost leaf of the left subtree