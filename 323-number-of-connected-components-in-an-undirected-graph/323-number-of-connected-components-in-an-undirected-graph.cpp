class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> visited(n, false);
        int ans =0;
        
        for(int i =0; i<n; i++)
        {
            if(!visited[i])
            {
                // dfs(adj, visited, i);
                bfs(adj, visited, i);
                ans++;
            }
        }
        return ans;
        
    }
    
    void bfs(vector<vector<int>> &adj, vector<bool>&visited, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(auto it: adj[curr])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
    }
    
//     void dfs(vector<vector<int>> &adj, vector<bool>&visited, int node)
//     {
//         visited[node] = true;
        
//         for(auto it: adj[node])
//         {
//             if(!visited[it])
//                 dfs(adj, visited, it);
//         }
//     }
    
    
};