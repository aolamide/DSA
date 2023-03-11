/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* buildBST(int left, int right, ListNode* &head) 
    {
        if (left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode *leftNode = buildBST(left, mid - 1, head);
        
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        
        root->left = leftNode;
        root->right = buildBST(mid + 1, right, head);

        return root;
    }
    
    int length(ListNode *head) {
        int ans = 0;
        while (head) {
            head = head->next;
            ans++;
        }
        return ans;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(0, length(head) - 1, head);
    }
}; 