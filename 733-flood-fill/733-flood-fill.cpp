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
    
    void helper(vector<vector<int>>& image, int cr, int cc, int newColor, int row, int col, int color)
    {
        if(cr < 0 || cc < 0 || cr >= row || cc >= col || image[cr][cc] != color )
            return;
        
        image[cr][cc] = newColor;
        
        helper(image, cr + 1, cc, newColor, row, col, color);
         helper(image, cr - 1, cc, newColor, row, col, color);
         helper(image, cr , cc + 1, newColor, row, col, color);
         helper(image, cr , cc - 1, newColor, row, col, color);
        
        return;
        
    }
    
};