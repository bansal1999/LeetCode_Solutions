class Solution {
public:
    
    bool dfs(vector<vector<int>> &graph, vector<int>&visited, int current, int end)
    {
        if(current == end)
            return true;
        if(visited[current])
            return false;
        
        visited[current] = 1;
        
        for(auto it : graph[current])
        {
            if (dfs(graph, visited, it, end))
                return true;
        }
        
        return false;
        
    }
    
    
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        
        for(auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        vector<int> visited(n, 0);
        
         return dfs(graph, visited, start, end);
        
    }
};