class Solution {
public:
    vector<vector<int>>constructGraph(int numCourses, vector<vector<int>>& prerequisites ){
        
        vector<vector<int>> edges(numCourses);
        
        for(auto &it:prerequisites){
            edges[it[1]].push_back(it[0]);
        }
        return edges;
    }
    
    bool checkCycle(int node, int numCourses, vector<vector<int>> &graph, vector<int> &visited, vector<int> &dfsVis, vector<int> &topoSort) {
        
        visited[node] = 1;
        dfsVis[node] = 1;
        
        for(auto &it: graph[node]){
            if(visited[it] != 1){
                if(checkCycle(it, numCourses, graph, visited, dfsVis, topoSort) == true){
                    return true;
                }
            }
            else if(dfsVis[it] == 1){
                return true;
            }
        }
        topoSort.push_back(node);
        dfsVis[node] = 0;
        return false;
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = constructGraph(numCourses, prerequisites);
        
        vector<int> visited(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);
        vector<int> topoSort;
        
        for(int i =0; i < numCourses; i++){
            if(visited[i] != 1){
                if(checkCycle(i, numCourses, graph, visited, dfsVis, topoSort) == true){
                    return {};
                }
            }
        }
        reverse(topoSort.begin(), topoSort.end());
        return topoSort;
        
    }
};