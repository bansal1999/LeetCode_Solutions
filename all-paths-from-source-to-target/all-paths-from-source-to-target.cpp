class Solution {
public:
    
    void dfs_helper(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> path, int src, int dst )
    {
        path.push_back(src);
        
        if(src == dst)
        {
            result.push_back(path);
            return;
        }
        
        for(auto it: graph[src])
        {
            dfs_helper(graph, result, path, it, dst);
        }
        
        
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<vector<int>> result; vector<int> path;
        int nodes = graph.size();
        
        if(nodes == 0)
            return result;
        
        dfs_helper(graph, result, path, 0, nodes-1);
        
        return result;
    }
};