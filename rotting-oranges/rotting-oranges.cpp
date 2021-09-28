class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
          
        if(grid.empty())
            return 0;
        
        int freshOranges = 0;
        int r = grid.size();
        int c = grid[0].size();
        
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<r; i++)
        {
            for(int j =0; j<c; j++)
            {
                if(grid[i][j] == 1)
                    freshOranges++;
                
                if(grid[i][j] == 2)
                    q.push({i, j});
                
            }
        }
        
        int time =0;
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {-1, 0}, {0,-1}};
        
        while(freshOranges != 0 && !q.empty())
        {
            int qsize = q.size();
            
            for(int i=0; i< qsize; i++)
            {
                int rottenI = q.front().first;
                int rottenJ = q.front().second;
                
                q.pop();
                
                for(auto d : dirs)
                {
                    int newX = rottenI + d.first;
                    int newY = rottenJ + d.second;
                    
                    if(newX >= 0 && newX < r && newY >= 0 && newY < c && grid[newX][newY] == 1 )
                    {
                        grid[newX][newY] = 2;
                        freshOranges--;
                        q.push({newX, newY});
                    }
                }
            }
            time++;
            
        }
        
        return freshOranges == 0 ? time : -1;
        
        
        
    }
};