class Solution {
public:
    int helper(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
    {
        if(i < 0)
            return j +1;
        if(j < 0)
            return i + 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(str1[i] == str2[j])
            return dp[i][j] = helper(i-1, j-1, str1, str2, dp);
        
        return dp[i][j] = 1 + min(helper(i, j-1, str1, str2, dp) , 
                                min(helper(i-1, j, str1, str2, dp), 
                                    helper(i-1, j-1, str1, str2, dp)));
        
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, word1, word2, dp);
    }
};