// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string currPath;
        generatePath(m, n, 0, 0, currPath, ans);
        
        return ans;
    }
    
    void generatePath(vector<vector<int>> &grid, int &n, int currRow, int currCol, string &currPath, vector<string> &path )
    {
        // base case -> invalid cells
        if(currRow >= n || currRow < 0 || currCol >= n || currCol < 0)
            return ;
            
        // cell blocked condition
        if(grid[currRow][currCol] == 0)
            return;
            
        //reached destination --> pushing the current string to answer
        if(currRow == n-1 && currCol == n-1)
        {
              path.push_back(currPath);
              return;
        }
        
        //marking the current cell visited to avoid infinite recurssive calls
        grid[currRow][currCol] = 0;
        
        //up movement
        currPath += "U";
        generatePath(grid, n, currRow -1, currCol, currPath, path);
        currPath.pop_back();
        
        //down movement
        currPath += "D";
        generatePath(grid, n, currRow + 1, currCol, currPath, path);
        currPath.pop_back();
        
        
        //left movement
        currPath += "L";
        generatePath(grid, n, currRow , currCol - 1, currPath, path);
        currPath.pop_back();
        
        
        //right movement
        currPath += "R";
        generatePath(grid, n, currRow , currCol + 1, currPath, path);
        currPath.pop_back();
 
        //BackTracking step
        grid[currRow][currCol] = 1;
        
        return;

    }
    
};
    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends