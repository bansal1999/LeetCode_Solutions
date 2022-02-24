class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> colors(n, -1);
        
        for(int curr = 0; curr < n; curr++)
        {
            if(colors[curr] == -1)
            {
                if(!checkDFS(graph, curr, colors))
                    return false;
            }
        }
        return true;
    }
    
    bool checkDFS(vector<vector<int>> &graph, int curr, vector<int>& colors)
    {
        if(colors[curr] == -1)
            colors[curr] = 1;
        
        for(auto  it: graph[curr])
        {
            if(colors[it] == -1)
            {
                colors[it] = 1 - colors[curr];
                if(!checkDFS(graph, it, colors))
                    return false;
                
            }
            else if(colors[curr] == colors[it])
                return false;
        }
        
        return true;
    }

};