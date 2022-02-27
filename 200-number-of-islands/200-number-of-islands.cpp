class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        int ans=0;
        
        for(int i =0; i< r; i++)
        {
            for(int j =0; j < c;j++)
            {
                if(grid[i][j] == '1')
                {
                    ans += 1;
                    helper(grid, i , j, r, c);
                }
                
            }
        }
        return ans;
    }
    
    void helper(vector<vector<char>>& grid, int cr, int cc, int r, int c)
    {
        if(cr >= r || cc >= c || cr < 0 || cc < 0 || grid[cr][cc] == '0')
            return;
        
        grid[cr][cc] = '0';
        
        helper(grid, cr + 1, cc, r, c);
        helper(grid, cr - 1, cc, r, c);
        helper(grid, cr , cc + 1, r, c);
        helper(grid, cr , cc - 1, r, c);
        
        return;
    }
    
};