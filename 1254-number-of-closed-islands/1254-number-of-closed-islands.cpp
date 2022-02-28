class Solution {
public:
    int row, col;
    
    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        for(int i=0; i< row; i++)
        {
            for(int j =0; j< col; j++)
            {
                if((i == row -1 || j == col - 1 || i==0 || j==0) && (grid[i][j] == 0))
                    dfs(grid, i, j );
            }
        }
        
        int cnt = 0;
        
        for(int cr =0; cr < row; cr++)
        {
            for(int cc =0; cc < col; cc++)
            {
                if(grid[cr][cc] == 0)
                {
                    cnt += 1;
                    dfs(grid, cr, cc);
                }
            }
        }
        
        return cnt;
    }
    
    void dfs(vector<vector<int>> &grid, int cr, int cc)
    {
        if(cr < 0 || cc < 0 || cr >= row || cc >= col || grid[cr][cc] != 0)
            return;
        
        grid[cr][cc] = -1;
        
        dfs(grid, cr + 1, cc);
        dfs(grid, cr - 1, cc);
        dfs(grid, cr, cc + 1);
        dfs(grid, cr, cc - 1);
        
        return;
        
    }
};