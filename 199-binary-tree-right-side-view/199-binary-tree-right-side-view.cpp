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

//BFS Solution
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if(!root) return {};
        
//         queue<TreeNode*> q;
//         vector<int> result;

//         int levelCount = 1;
//         int count = 0;

//         q.push(root);

//         while(!q.empty()) {
//             root = q.front();
//             q.pop();
//             count++;

//             if(root->left) q.push(root->left);
//             if(root->right) q.push(root->right);

//             if(count == levelCount) {
//                 result.push_back(root->val);
//                 levelCount = q.size();
//                 count = 0;
//             }
//         }
        
//         return result;
//     }
// };


//DFS Solution
class Solution {
public:
    vector<int> result;
    set<int> levelSet;
    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        
        preorder(root, level);

        return result;
    }
private:
    void preorder(TreeNode *root, int level) {
        if(!root) return;
        level++;
        if(!levelSet.count(level)) {
            result.push_back(root->val);
            levelSet.insert(level);
        }
        preorder(root->right, level);
        preorder(root->left, level);
    }
};