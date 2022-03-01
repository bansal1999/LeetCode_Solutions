class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int  row = grid.size(), col= grid[0].size();
        int freshOranges = 0;
        
        queue<pair<int, int>> q;
        
        for(int i =0; i< row; i++)
        {
            for(int j =0; j < col; j ++)
            {
                if(grid[i][j] == 1)
                    freshOranges++;
                
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        int time =0;
        vector<pair<int, int>> dirs = {{-1,0} ,{0, 1}, {1, 0}, {0, -1}};
        
        while(!q.empty() && freshOranges!= 0)
        {
            int qsize = q.size();
            for(int i =0; i< qsize; i++)
            {
                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                for(auto it: dirs)
                {
                    int newX = it.first + x;
                    int newY = it.second + y;

                    if(newX >= 0 && newX < row && newY >= 0 && newY < col && grid[newX][newY] == 1)
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