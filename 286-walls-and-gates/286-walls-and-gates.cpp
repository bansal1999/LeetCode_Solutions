class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size();
        int col = rooms[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {0, -1}, {1, 0} };
        queue<pair<int, int>> q;
        
        for(int i =0; i< row; i++)
        {
            for(int j =0; j < col; j++)
            {
               if(rooms[i][j] == 0)
                   q.push({i, j});
            }
        }
        
        while(!q.empty())
        {
            auto curr = q.front();
            int x = curr.first;
            int y = curr.second;
            q.pop();
            
            for(auto it: dirs)
            {
                int newX = x + it.first;
                int newY = y + it.second;
                
                if(newX < 0 || newX >= row || newY < 0 || newY >= col || rooms[newX][newY] <= rooms[x][y] + 1 || rooms[newX][newY] == -1 )
                    continue;
                
                rooms[newX][newY] = rooms[x][y] + 1;
                q.push({newX, newY});
            }
            
        }
        
    }
};