class Solution {
public:
    int getCount(int num, vector<vector<int>>& matrix) { //o(n)
        int n = matrix.size();
        int r = 0;
        int c = n - 1;
        int count = 0;
        while(r < n && c >= 0) { 
            if(matrix[r][c] <= num) {
                count += c + 1;
                r++;
            }else {
                c--;
            }
        }

        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int min = matrix[0][0];
        int max = matrix[n - 1][n - 1];

        while(min != max) { //o(log(max - min))
            int mid = min + (max - min) / 2;

            int count = getCount(mid, matrix);

            if(count < k) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }

        return min;

        //time: o(nlog(max - min));
        //space : o(1)
    }
};