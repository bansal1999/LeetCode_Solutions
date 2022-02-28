class Solution {
public:
    int row, col;
    
    int numEnclaves(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        for(int i =0; i< row; i++)
        {
            for(int j =0; j < col; j++)
            {
                if((i == 0 || j == 0 || i == row -1 || j == col - 1) && (grid[i][j] == 1))
                    dfs(grid, i, j);
            }
        }
        
        int ans =0;
        for(int i =0; i< row; i++)
        {
            for(int j =0; j < col; j++)
            {
                if(grid[i][j] == 1)
                    ans++;
            }
        }
        
        return ans;
        
    }
    
    void dfs(vector<vector<int>> &grid, int cr, int cc)
    {
        if(cr < 0 || cc < 0 || cr >= row || cc >= col || grid[cr][cc] != 1)
            return;
        
        grid[cr][cc] = 0;
        
        dfs(grid, cr + 1, cc);
         dfs(grid, cr - 1, cc);
         dfs(grid, cr, cc + 1);
         dfs(grid, cr, cc -1);
        
        return;
    }
    
};