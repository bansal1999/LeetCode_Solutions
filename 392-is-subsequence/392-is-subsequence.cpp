class Solution {
public:
    bool helper(string s, string t, int i, int j,  vector<vector<int>> &dp){
        if(i < 0){
            return true;
        }
        
        if(j < 0){
            return false;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s[i] == t[j]){
            return dp[i][j] = helper(s, t, i-1, j-1, dp);
        }
        else{
            return dp[i][j] = helper(s, t, i, j-1, dp);
        }
        
    }
    
    
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp( n, vector<int>(m, -1));
        
        return helper(s, t, n-1, m-1, dp);
    }
};