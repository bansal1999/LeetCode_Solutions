class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         
        int n = graph.size();
        vector<vector<int>> ans;
        // vector<bool> visited(n);
        vector<int> currPath;
       
        helper(graph, ans, currPath, 0, n);
        return ans;
    }
    
    void helper(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> currPath, int currNode, int n)
    {
        if(currNode == n-1)
        {
            currPath.push_back(currNode);
            ans.push_back(currPath);
            currPath.pop_back();
            return;
        }
        
        // if(visited[currNode] == true)
        //     return;
        
        // visited[currNode] = true;
        currPath.push_back(currNode);
        
        for(auto it: graph[currNode])
        {
            helper(graph, ans, currPath, it, n);
        }
        
//         visited[currNode] = false;
        currPath.pop_back();
        return;
        
    }
};