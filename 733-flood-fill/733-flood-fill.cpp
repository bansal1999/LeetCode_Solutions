class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        
        if(image[sr][sc] == newColor)
            return image;
        
        helper(image, sr, sc, newColor, row, col, image[sr][sc]);
        return image;
    }
    
    void helper(vector<vector<int>>& image, int currRow, int currCol, int newColor, int row, int col, int color)
    {
        if(currCol < 0 || currRow < 0  || currCol >= col || currRow >= row || image[currRow][currCol] != color)
        {
            return;
        }
        
        image[currRow][currCol] = newColor;
        
        helper(image, currRow + 1, currCol, newColor, row, col, color);
         
        helper(image, currRow  -1, currCol, newColor, row, col, color);
        
        helper(image, currRow, currCol + 1, newColor, row, col, color);
          
        helper(image, currRow, currCol -1 , newColor, row, col, color);
        
        return;
        
    }
};