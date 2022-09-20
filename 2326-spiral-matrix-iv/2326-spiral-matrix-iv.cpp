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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> dir = {0, 1};
        vector<vector<int>> result(m, vector<int>(n, -1));
        int r = 0;
        int c = 0;
        
        while(head) {
            result[r][c] = head->val;
            int nextR = r + dir[0];
            int nextC = c + dir[1];
            
            if(nextR < 0 || nextR == m || nextC < 0 || nextC == n || result[nextR][nextC] != -1) {
                int diff = dir[1] - dir[0];
                if(dir[0] == 0) {
                    //go down or up
                    dir[0] += diff;
                    dir[1] = 0;
                } else {
                    //go left or right
                    dir[1] += diff;
                    dir[0] = 0;
                }
                nextR = r + dir[0];
                nextC = c + dir[1];
            }
            r = nextR;
            c = nextC;
            head = head->next;
        }
        
        return result;
    }
};