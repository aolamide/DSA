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
    int heightOfCompleteTree(TreeNode *root) {
        int height = 0;
        
        while(root->left) {
            height++;
            root = root->left;
        }
        
        return height;
    }
    
    int nodeExistsAtLastLevel(int nodePos, int height, TreeNode *root) {
        int l = 0, r = pow(2, height) - 1, level = 0;
        
        while(level < height) {
            int mid = (l + r + 1) / 2;
            
            if(mid <= nodePos) {
                root = root->right;
                l = mid;
            } else {
                root = root->left;
                r = mid - 1;
            }
            level++;
        }
        
        return !!root;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int height = heightOfCompleteTree(root);

        if(!height) return 1;
        
        int upperCount = pow(2, height) - 1;
        
        int left = 0, right = upperCount;
        
        while(left < right){
            int mid = (left + right + 1) / 2;
            
            if(nodeExistsAtLastLevel(mid, height, root)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return upperCount + right + 1;
    }
};