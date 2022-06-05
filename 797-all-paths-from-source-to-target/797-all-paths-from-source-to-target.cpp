class Solution {
public:
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<bool> visited(n);
        vector<vector<int>> ans;
        
        helper(graph, 0, n, path, visited, ans);
        return ans;
    }
    
    void helper(vector<vector<int>>& graph, int currNode, int n, vector<int> &path, vector<bool> &visited, vector<vector<int>> &ans) {
        
        if(currNode == n-1){
            path.push_back(currNode);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        if(visited[currNode] == true)
            return;
        
        visited[currNode] = true;
        
        path.push_back(currNode);
        
        for(auto &it: graph[currNode]){
            helper(graph, it, n, path, visited, ans);
        }
        
        visited[currNode]= false;
        path.pop_back();
        return;
        
    }
    
    
};