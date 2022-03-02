class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        vector<pair<int, int>> dirs = {{-1, 0},  {0, 1} , {1, 0}, {0, -1} , {-1, -1}, {-1, 1}, {1,1} , {1, -1}};
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        grid[0][0] = 1;
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
           
            
            if(x == n-1 && y == n-1)
                return grid[x][y];
            
            for(auto it: dirs)
            {
                int nx = x + it.first;
                int ny = y + it.second;
                
                if(nx >= 0 && nx < n && ny >= 0  && ny < n && grid[nx][ny] == 0)
                {
                    q.push({nx, ny});
                    grid[nx][ny]= grid[x][y] + 1;
                }
                
            }
             q.pop();
        }
        return -1;
    }
};