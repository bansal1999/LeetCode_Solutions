class Solution {
public:
    vector<vector<int>>constructGraph(int numCourses, vector<vector<int>>& prerequisites ){
        
        vector<vector<int>> edges(numCourses);
        
        for(auto &it:prerequisites){
            edges[it[1]].push_back(it[0]);
        }
        return edges;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = constructGraph(numCourses, prerequisites);
        
        vector<int> indegree(numCourses, 0);
        
        for(int i =0; i< numCourses; i++){
            for(auto &it: graph[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        vector<int> topoSort;
        int ans = 0;
        
        for(int i =0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            ans++;
            for(auto &it: graph[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(ans == numCourses){
            return topoSort;
        }
        
        return {};
    }
};