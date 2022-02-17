class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc] == newColor)
            return image;
        
        int row = image.size();
        int col = image[0].size();
        
        int color = image[sr][sc];
        queue<pair<int, int>> q;
        
        q.push({sr, sc});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int currRow = it.first;
            int currCol = it.second;
            
            if(currRow < 0 || currCol < 0 || currRow >= row || currCol >= col || image[currRow][currCol] != color)
                continue;
            
            image[currRow][currCol] = newColor;
            
            q.push({currRow + 1, currCol});
            q.push({currRow - 1, currCol});
            q.push({currRow, currCol + 1});
            q.push({currRow, currCol - 1});
            
        }
        
        return image;
    }
};