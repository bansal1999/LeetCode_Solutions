class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cn = connections.size();
        
        if(cn < n-1)
            return -1;
        
        vector<vector<int>> adj(n);
        for(auto it: connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> visited (n, false);
        int cmp =0;
        
        for(int i =0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(adj, visited, i);
                cmp++;
                
            }
        }
        
        return cmp - 1;
    }
    
    void dfs(vector<vector<int>>& connections, vector<bool> &visited, int node)
    {
        visited[node] = true;
        for(auto  it: connections[node])
        {
            if(!visited[it])
                dfs(connections, visited, it);
        }
    }
    
};