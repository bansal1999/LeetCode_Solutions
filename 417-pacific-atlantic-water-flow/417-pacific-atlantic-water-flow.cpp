class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacificVis(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticVis(m, vector<bool> (n, false));
        
        queue<pair<int,  int>> pacificQ;
        queue<pair<int, int>> atlanticQ;
        
        for(int i =0; i< m; i++)
        {
            for(int j =0; j < n; j++)
            {
                if(i == 0 || j == 0)
                {
                    pacificQ.push({i, j});
                    pacificVis[i][j] = true;
                }
                
                if(i == m -1 || j == n -1)
                {
                    atlanticQ.push({i, j});
                    atlanticVis[i][j] = true;
                }
            }
        }
        
        vector<vector<int>> ans;
        bfs(pacificQ, pacificVis, heights);
        bfs(atlanticQ, atlanticVis, heights);
        
        for(int i =0; i<m; i++)
        {
            for(int j =0; j < n; j++)
            {
                if(pacificVis[i][j] == true && atlanticVis[i][j] == true)
                    ans.push_back({i, j});
            }
        }
        return ans;
        
    }
    
    void bfs(queue<pair<int, int>> q, vector<vector<bool>>& visited, vector<vector<int>>& heights )
    {
        int row = heights.size();
        int col = heights[0].size();
        
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0} , {0, -1}};
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto &it: dirs)
            {
                int nx = x + it.first;
                int ny = y + it.second;
                
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && heights[nx][ny] >= heights[x][y] && visited[nx][ny] == false)
                {
                    q.push({nx, ny});
                    visited[nx][ny]= true;
                }
            }
        }
        return;
    }
};