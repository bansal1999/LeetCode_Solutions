class Solution {
    
private:
    int n, m;
    int dp[71][71][71];

private:
    int helper(int row, int col1, int col2, vector<vector<int>>& grid )
    {
        int dy[] = {-1, 0, 1};
        
        if(row == n)
            return 0;
        
        if(col1 < 0 || col1 >= m || col2 <0 || col2 >= m)
            return INT_MIN;
        
        if(dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        
        int maxi =0;
        
        for(int i =0; i< 3; i++)
        {
            for(int j = 0; j< 3; j++)
            {
                int newRow = row + 1;
                int newCol1 = col1 + dy[i];
                int newCol2 = col2 + dy[j];
                
                
                if(col1 == col2)
                {
                    maxi = max(maxi, grid[row][col1] + helper(newRow, newCol1, newCol2, grid));
                }
                else
                {
                    maxi = max(maxi, grid[row][col1] + grid[row][col2] + helper(newRow, newCol1, newCol2, grid));
                }
            }
        }
        
        return dp[row][col1][col2] = maxi;
        
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        
         memset(dp, -1, sizeof dp);
        return helper(0, 0, m-1, grid);
    }
};