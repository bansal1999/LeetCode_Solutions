class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc] == newColor){
            return image;
        }
        
        int m = image.size();
        int n = image[0].size();
        
        helper(image, sr, sc, image[sr][sc], newColor, m, n);
        return image;
    }
    
    void helper(vector<vector<int>>& image, int row, int col, int color, int newColor, int m, int n){
        if(row >= m  || row < 0 || col >= n || col < 0 || image[row][col] != color){
            return;
        }
        
        image[row][col] = newColor;
        
        helper(image, row + 1, col, color, newColor, m, n);
        helper(image, row, col + 1, color, newColor, m, n);
        helper(image, row - 1, col, color, newColor, m, n);
        helper(image, row, col - 1, color, newColor, m, n);
        
        
    }
};