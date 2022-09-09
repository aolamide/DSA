class Solution {
public:
    int startColor;
    int newColor;
    vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    void dfs(vector<vector<int>>& image, int row, int col) {
        if(row < 0 || col >= image[0].size() || row >= image.size() || col < 0 || image[row][col] != startColor) return;


        image[row][col] = newColor;


        for(int i = 0; i < 4; i++) {
            dfs(image, row + directions[i][0], col + directions[i][1]);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        newColor = color;
        startColor = image[sr][sc];

        if(newColor == startColor) return image;

        dfs(image, sr, sc);

        return image;
        
    }
};

//time = O(rows x cols);