class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        int maxAns =0;
        
        for(int i =0; i<r; i++)
        {
            for(int j =0; j<c; j++)
            {
                if(grid[i][j] == 1)
                {
                    int ans =0;
                    ans = helper(grid, i, j, r, c);
                    maxAns = max(ans, maxAns);
                }
            }
        }
        
        return maxAns;
    }
    
    int helper(vector<vector<int>> &grid, int cr, int cc, int r, int c )
    {
        if(cr < 0 || cc < 0 || cr >= r || cc >= c || grid[cr][cc] == 0)
            return 0;
        
        grid[cr][cc] = 0;
        
        return (1 + helper(grid, cr + 1, cc, r, c) + helper(grid, cr - 1, cc, r, c) + helper(grid, cr, cc +1, r, c) + helper(grid, cr, cc -1, r, c) );
            
    }
    
};