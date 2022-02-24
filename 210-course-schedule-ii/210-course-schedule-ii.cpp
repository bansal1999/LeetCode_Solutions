class Solution {
public:
    vector<vector<int>> constructGraph(int n, vector<vector<int>>&edges)
    {
        vector<vector<int>> graph(n);
        for(auto it: edges)
        {
            int v = it[0];
            int u = it[1];
            
            graph[u].push_back(v);
        }
        
        return graph;
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = constructGraph(numCourses, prerequisites);
        unordered_set<int> visited;
        unordered_set<int> dfsVisited;
        
        vector<int> toposort;
        
        for(int currVertex = 0; currVertex < numCourses; currVertex++)
        {
            if(visited.find(currVertex) != visited.end())
                continue;
            
            if(isCycle(graph, currVertex, visited, dfsVisited, toposort))
                return {};
        }
        
        reverse(toposort.begin(), toposort.end());
        return toposort;
        
    }
    
    bool isCycle(vector<vector<int>> &graph, int currVertex, unordered_set<int>&visited, unordered_set<int>&dfsVisited, vector<int>& toposort)
    {
        visited.insert(currVertex);
        dfsVisited.insert(currVertex);
        
        for(auto neighbour: graph[currVertex])
        {
            if(visited.find(neighbour) == visited.end())
            {
                if(isCycle(graph, neighbour, visited, dfsVisited, toposort))
                    return true;
            }
            else if(dfsVisited.find(neighbour) != dfsVisited.end())
                return true;
        }
        
        toposort.push_back(currVertex);
        dfsVisited.erase(currVertex);
        
        return false;
    }
    
};