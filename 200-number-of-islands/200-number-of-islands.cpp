class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        
        for(int i =0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    ans += 1;
                    helper(grid, row, col, i, j);
                }
            }
        }
       return ans;
    }
    
    void helper(vector<vector<char>>& grid, int row, int col, int currRow, int currCol){
        
        if(currRow < 0 || currCol < 0 || currRow >= row || currCol >= col || grid[currRow][currCol] == '0')
            return;
        
        grid[currRow][currCol] = '0';
        
        helper(grid, row, col, currRow + 1, currCol);
         helper(grid, row, col, currRow - 1, currCol);
         helper(grid, row, col, currRow, currCol + 1);
         helper(grid, row, col, currRow, currCol - 1);
        
        return;
        
    }
    
    
};