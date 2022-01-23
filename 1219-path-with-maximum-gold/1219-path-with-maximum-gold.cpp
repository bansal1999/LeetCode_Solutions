class Solution {
public:
    
    int ans = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        
        for(int i = 0; i< grid.size(); i++)
        {
            for(int j =0; j< grid[0].size(); j++)
            {
                if(grid[i][j] != 0)
                    dfs(grid, i, j, 0);
                    
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>> &grid, int x, int y, int curr)
    {
        if( x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return;
        
        if(grid[x][y] == 0 || grid[x][y] == -1)
            return;
        
        int ele = grid[x][y];
        grid[x][y] = -1;
        curr += ele;
        ans = max(ans, curr);
        
        dfs(grid, x + 1, y, curr);
        dfs(grid, x - 1, y, curr);
        dfs(grid, x , y + 1, curr);
        dfs(grid, x , y - 1, curr);
        
        grid[x][y] = ele;
    }
    
};