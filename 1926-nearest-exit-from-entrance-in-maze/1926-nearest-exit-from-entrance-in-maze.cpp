class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int row = maze.size();
        int col = maze[0].size();
        
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0,-1}};
        int sr = entrance[0], sc = entrance[1];
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        maze[sr][sc] = '+';
        int moves = 1;
        
        
        while(!q.empty())
        {
            int qsize = q.size();
            for(int i =0; i< qsize; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(auto it: dirs)
                {
                    int nx = x + it.first;
                    int ny = y + it.second;

                    if(nx < 0 || nx >= row || ny < 0 || ny >= col || maze[nx][ny] == '+')
                        continue;

                    if(nx == 0 || nx == row - 1 || ny == 0 || ny == col -1)
                        return moves;

                    q.push({nx, ny});
                    maze[nx][ny] = '+';
                }
                
            }
            
             moves++;
            
        }
        return -1;
        
    }
};