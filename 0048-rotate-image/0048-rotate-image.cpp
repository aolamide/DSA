class Solution {
public:
    void swap(int x1, int y1, int x2, int y2, vector<vector<int>>& matrix) {
        int tmp = matrix[x1][y1];

        matrix[x1][y1] = matrix[x2][y2];

        matrix[x2][y2] = tmp;
    }

    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) { 
            for(int j = i + 1; j < n; j++) { 
                swap(i, j, j, i, matrix);
            }
        }
    }

    void reflect(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) { 
            int l = 0, r = n - 1;

            while(l <= r) {
                swap(i, l, i, r, matrix); 
                l++;
                r--;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {

        transpose(matrix); 

        reflect(matrix);     
    }
};