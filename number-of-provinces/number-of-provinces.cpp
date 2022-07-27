class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans =0;
        
        for(int i =0; i< n; i++)
        {
            if(!visited[i])
            {
                dfs(isConnected, visited, i);
                ans++;
            }
        }
        return ans;
        
    }
    
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int node)
    {
        visited[node] = true;
        for(int i =0; i< isConnected[node].size(); i++)
        {
            if(i == node)
                continue;
            if(isConnected[node][i] && !visited[i])
                dfs(isConnected, visited, i);
        }
    }
};