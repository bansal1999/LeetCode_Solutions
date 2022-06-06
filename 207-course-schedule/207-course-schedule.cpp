class Solution {
public:
    vector<vector<int>> constructGraph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> edges(numCourses);
        
        for(auto it: prerequisites){
            edges[it[1]].push_back(it[0]);
        }
        return edges;
    }
    
    bool dfsCheckcycle(int node, int numCourses, vector<vector<int>> &graph, vector<int> &visited , vector<int> &dfsVis) {
        
        visited[node] = 1;
        dfsVis[node] = 1;
        
        for(auto &it: graph[node]){
            if(visited[it] != 1){
                if(dfsCheckcycle(it, numCourses, graph, visited, dfsVis ) == true){
                    return true;
                }
            }
            else if(dfsVis[it] == 1){
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
        
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = constructGraph(numCourses, prerequisites);
        
        vector<int> visited(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);
        
        for(int i =0; i< numCourses; i++ ){
           
            if(dfsCheckcycle(i, numCourses, graph, visited, dfsVis) == true){
                return false;
            } 
        } 
        return true;
    }
};