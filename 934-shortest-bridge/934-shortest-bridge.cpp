class Solution {
public:
    queue<pair<int, int>> q;
    
    void dfs(vector<vector<int>> &grid, int cr, int cc, int n)
    {
        if(cr < 0 || cr >= n || cc < 0 || cc >= n || grid[cr][cc] == 2 || grid[cr][cc] == 0 )
            return;
        
        q.push({cr, cc});
        grid[cr][cc] = 2;
        
        dfs(grid, cr + 1, cc, n);
        dfs(grid, cr - 1, cc, n);
        dfs(grid, cr, cc +1, n);
        dfs(grid, cr, cc - 1, n);
        
        return;
        
    }
    
    int bfs(vector<vector<int>> &grid, int n)
    {
        vector<pair<int, int>>  dirs = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};
        int d =0, mindst = INT_MAX;
        
        while(!q.empty())
        {
                int qsize = q.size();
                while(qsize-- > 0)
                {
                    int xr = q.front().first;
                    int yc = q.front().second;
                    q.pop();

                    for(auto it: dirs)
                    {
                        int nxr = xr + it.first;
                        int nyc = yc + it.second;

                        if(nxr >= 0 && nxr < n && nyc >= 0 && nyc < n && grid[nxr][nyc] == 1)
                        {
                            // if(grid[nxr][nyc] == 1)
                            // {
                            //     mindst = min(mindst, d);
                            // }
                            mindst = min(mindst, d);
                        }
                        else if(nxr >= 0 && nxr < n && nyc >= 0 && nyc < n && grid[nxr][nyc] == 0)
                        {
                                grid[nxr][nyc] = 2;
                                q.push({nxr, nyc});
                        }


                    }
                   
                }
             d++;
        }
        
        return mindst;
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool flag = false;
        
        for(int i =0; i< n; i++)
        {
            for(int j =0; j < n; j++)
            {
                if(grid[i][j] == 1 && !flag)
                {
                    dfs(grid, i, j, n);
                    q.push({i, j});
                    flag = true;
                    break;
                }
            }
            
            if(flag)
                break;  
        }
        
        return bfs(grid, n);
    }
};
