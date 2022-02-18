class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        int ans =0;
        
        for(int currRow =0; currRow< row; currRow++)
        {
            for(int currCol =0; currCol< col; currCol++)
            {
                if(grid[currRow][currCol] == '1')
                {
                    ans += 1;
                    helper(grid, currRow, currCol, row, col);
                }
            }
        }
        
        return ans;
    }
    
    void helper(vector<vector<char>>& grid, int currRow, int currCol, int row, int col)
    {
        if(currRow < 0 || currCol < 0 || currRow >= row || currCol >= col|| grid[currRow][currCol] == '0')
            return;
        
        grid[currRow][currCol] = '0';
        
        helper(grid, currRow + 1, currCol, row, col);
        helper(grid, currRow - 1, currCol , row, col);
        helper(grid, currRow , currCol + 1, row, col);
        helper(grid, currRow, currCol -1 , row, col);
        
        return;
    }
};