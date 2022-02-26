class Solution {
    vector<vector<int>> dirs = {{-1, 0} , {0, 1} , {1, 0} , {0, -1}};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        const int m = maze.size();
        const int n = maze[0].size();
        
       vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        
        q.push({start[0], start[1]});
        
        visited[start[0]][start[1]] = 1;
        
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            if(curr.first == destination[0] && curr.second == destination[1])
            {
                return true;
            }
            
            for(const auto &d: dirs)
            {
                int x = curr.first;
                int y = curr.second;
                
                while(x >= 0 && x < m && y >= 0 && y < n && !maze[x][y])
                {
                    x += d[0];
                    y += d[1];
                }
                
                x -= d[0];
                y -= d[1];
                
                if(!visited[x][y])
                {
                    q.push({x, y});
                    visited[x][y] = 1;
                }
                    
            }
        }
        return false;
    }
};