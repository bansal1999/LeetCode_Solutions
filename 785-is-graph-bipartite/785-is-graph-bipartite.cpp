class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        
        for(int curr =0; curr < n; curr++)
        {
            if(colors[curr] == -1)
            {
                if(!checkBFS(graph, curr, colors))
                    return false;
            }
        }
        
        return true;
    }
    
    bool checkBFS(vector<vector<int>> &graph, int curr, vector<int>&colors)
    {
        queue<int> q;
        q.push(curr);
        colors[curr] = 1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it: graph[node])
            {
                if(colors[it] == -1)
                {
                    colors[it] = 1 - colors[node];
                    q.push(it);
                }
                else if(colors[it] == colors[node])
                    return false;
            }
            
    
        }
        return true;
    }
};