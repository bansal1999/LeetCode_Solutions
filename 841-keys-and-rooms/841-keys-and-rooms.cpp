class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         vector<int> adj[rooms.size()];
        
//         for(int i =0; i< rooms.size(); i++)
//         {
//             for(int j =0; j< rooms[i].size(); j++)
//             {
//                 adj[i].push_back(rooms[i][j]);
//             }
//         }
        
        queue<int> q;
        
        vector<int> vis(rooms.size(),  0);
        vis[0] =1;
        
        q.push(0);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it: rooms[node])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        for(int i =0; i< rooms.size(); i++)
        {
            if(!vis[i])
                return false;
        }
        return true;
        
    }
};