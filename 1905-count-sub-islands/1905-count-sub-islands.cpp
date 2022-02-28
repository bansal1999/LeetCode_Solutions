class Solution {
public:
    int row, col;
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        row = grid2.size();
        col = grid2[0].size();
        
        int ans = 0;
        
        for(int i =0; i< row; i++)
        {
            for(int j =0; j<col; j++)
            {
                if(grid2[i][j] == 1)
                {
                    int res = true;
                    dfs(grid1, grid2, i, j, res);
                    ans += res;
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int cr, int cc, int &res)
    {
        if(cr < 0 || cc < 0 || cr >= row || cc >= col || grid2[cr][cc] == 0)
            return;
        
        if( grid1[cr][cc] == 0 && grid2[cr][cc] == 1)
            res = false;
        
        grid2[cr][cc] = 0;
        
        dfs(grid1, grid2, cr + 1, cc, res);
        dfs(grid1, grid2, cr - 1, cc, res);
        dfs(grid1, grid2, cr, cc +1, res);
        dfs(grid1, grid2, cr, cc - 1, res);
        
        return;
    }
    
    
};