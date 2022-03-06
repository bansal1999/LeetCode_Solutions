class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {0, 1} , {1, 0}, {0, -1}};
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        const int m = maze.size();
        const int n = maze[0].size();
        
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        
        vector<int> dist(m*n + 1,  0);
        for(int i =0; i<= m*n; i++)
        {
            dist[i] = INT_MAX;
        }
        
        dist[start[0]*n + start[1]] = 0;
        q.push({0, {start[0], start[1]}});
      
        while(!q.empty())
        {
            auto curr = q.top();
            int dis = curr.first;
            int cx = curr.second.first;
            int cy = curr.second.second;
            q.pop();

            for(auto &d: dirs)
            {
                int x = cx;
                int y = cy;
                int cnt =0;
                
                while(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0)
                {
                    x += d[0];
                    y += d[1];
                    cnt++;
                }
                
                x -= d[0];
                y -= d[1];
                cnt--;
               
                if(dis + cnt < dist[x*n + y])
                {
                    dist[x*n + y] = dis + cnt;
                    q.push({dis + cnt, {x, y}});
                }
                
            }
            
            
        }
        
        if(dist[destination[0]*n + destination[1]] == INT_MAX)
        {
            return -1;
        }
        return dist[destination[0]*n + destination[1]];
    }
};