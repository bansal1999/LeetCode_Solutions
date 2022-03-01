class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i< row; i++)
        {
            for(int j =0; j< col; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }
        
        int dist = 0;
        vector<pair<int, int>> dirs = {{-1, 0} , {0, 1} , {1, 0}, {0, -1}};
        
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            int x = curr.first;
            int y = curr.second;
            
            for(auto &it: dirs)
            {
                int newX = it.first + x;
                int newY = it.second + y;
                
                if( (newX < row && newY < col && newX >= 0 && newY >= 0) && (grid[newX][newY] == 0))
                {
                    q.push({newX, newY});
                    grid[newX][newY] = grid[x][y] + 1;
                    dist = max(dist, grid[newX][newY]);
                }
                
            }
        }
        
        return dist > 0 ? dist -1 : -1;
        
    }
};