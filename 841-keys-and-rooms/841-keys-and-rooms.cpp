class Solution {
public:
    void dfs(vector<vector<int>> &graph, int node, vector<int> &vis)
    {
        vis[node]= 1;
        
        for(int i = 0; i < graph[node].size(); i++)
        {
            if(!vis[graph[node][i]])
                dfs(graph, graph[node][i], vis);
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        
        dfs(rooms, 0, vis);
        
        for(int i =0; i< n; i++)
        {
            if(!vis[i])
                return false;
        }
        return true;
    }
};