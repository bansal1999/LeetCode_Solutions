class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        int m = s.size();
        int n = rev.size();
        
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                dp[i][j] =0;
            }
        }
        
        for(int i = 1; i<=m ; i++)
        {
            for(int j=1; j<= n ; j++)
            {
                if(s[i-1] == rev[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
        
        
        
    }
};