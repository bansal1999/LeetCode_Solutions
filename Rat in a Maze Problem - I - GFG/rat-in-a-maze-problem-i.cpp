// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void allPaths(int row, int col, vector<vector<int>> &m, int n, vector<string> &res, string ans ){
        if(row >= n || row < 0 || col >= n || col < 0 || m[row][col] == 0) {
            return;
        }
        
        if(row == n- 1 && col == n-1){
            res.push_back(ans);
            return;
        }
        
        m[row][col] = 0;
        
        allPaths(row + 1, col, m, n, res, ans + "D");
        allPaths(row, col + 1, m, n, res, ans + "R");
        allPaths(row, col - 1, m, n, res, ans + "L");
        allPaths(row - 1, col, m, n, res, ans + "U");
        
        m[row][col] = 1;
        
    }
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        string ans = "";
        allPaths(0, 0, m, n, res, ans);
        sort(res.begin(), res.end());
        return res;
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