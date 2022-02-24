class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> colors(n, -1);
        
        for(int curr = 0; curr < n; curr++)
        {
            if(colors[curr] != -1)
                continue;
            
            if(isEvenCycle(graph, curr, 0, colors) == false)
                return false;
        }
        return true;
    }
    
    bool isEvenCycle(vector<vector<int>> &graph, int curr, int color, vector<int>&colors)
    {
        if(colors[curr] != -1)
            return colors[curr] == color;
        
        colors[curr] = color;
        
        for(auto  it: graph[curr])
        {
            if(isEvenCycle(graph, it, 1 - color, colors) == false)
                return false;
        }
        
        return true;
    }
};