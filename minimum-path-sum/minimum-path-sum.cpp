class Solution {
public:
    int helper(int m, int n, int cr, int cc, vector<vector<int>>&grid, vector<vector<int>> &vec )
    {
        if(cr == m-1 && cc == n-1)
            return grid[cr][cc];
        
        if(cr >= m || cr < 0 || cc >= n || cc < 0)
            return 10000;
        
        if(vec[cr][cc] != -1)
            return vec[cr][cc];
        
        int right = grid[cr][cc] + helper(m, n, cr, cc +1, grid, vec);
        int down  = grid[cr][cc] + helper(m, n, cr +1, cc, grid, vec);
        
        return vec[cr][cc] = min(right, down);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vec(m, vector<int>(n, -1));
        
        return helper(m, n, 0, 0, grid, vec);
    }
};