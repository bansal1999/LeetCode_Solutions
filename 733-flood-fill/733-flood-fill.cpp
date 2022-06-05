class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc] == newColor){
            return image;
        }
        
        int row = image.size();
        int col = image[0].size();
        
        // helper(image, sr, sc, newColor, image[sr][sc], row, col);
        
        int color = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        while(!q.empty()){
            
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            
            if(currRow < 0 || currCol < 0 || currRow >= row || currCol >= col || image[currRow][currCol] != color)
                continue;
            
            image[currRow][currCol] = newColor;
            
            q.push({currRow + 1 , currCol});
            q.push({currRow - 1 , currCol});
            q.push({currRow , currCol + 1});
            q.push({currRow , currCol - 1});
            
        }
        
        return image;
    }
    
//     void helper(vector<vector<int>>& image, int currRow, int currCol, int newColor, int color, int row, int col) {
        
//         if(currRow < 0 || currCol < 0 || currRow >= row || currCol >= col || image[currRow][currCol] != color){
//             return;
//         }
        
//         image[currRow][currCol] = newColor;
        
//         helper(image, currRow + 1, currCol, newColor, color, row, col);
//         helper(image, currRow -1, currCol, newColor, color, row, col);
//         helper(image, currRow, currCol + 1, newColor, color, row, col);
//         helper(image, currRow, currCol - 1, newColor, color, row, col);
        
//         return;
//     }
};