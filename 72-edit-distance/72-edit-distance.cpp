class Solution {
public:
//     int helper(string &word1, string &word2, int ind1, int ind2, vector<vector<int>> &dp){
//         if(ind1 < 0){
//             return ind2 + 1;
//         }
        
//         if(ind2 < 0){
//             return ind1 + 1;
//         }
        
//         if(dp[ind1][ind2] != -1){
//             return dp[ind1][ind2];
//         }
        
//         if(word1[ind1] == word2[ind2]){
//             return dp[ind1][ind2] = 0 + helper(word1, word2, ind1 -1, ind2 - 1, dp );
//         }
//         else{
//             return dp[ind1][ind2] = 1 + min(helper(word1, word2, ind1 - 1, ind2, dp) , min(helper(word1, word2, ind1, ind2 - 1, dp) , helper(word1, word2, ind1 -1, ind2 - 1, dp)));
//         }
        
//     }
    
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i =0; i < n +1; i++){
            dp[i][0] = i;
        }
        
        for(int j = 0; j < m + 1; j++){
            dp[0][j] = j;
        }
        
        for(int ind1 = 1; ind1 < n +1; ind1++){
            for(int ind2 = 1; ind2 < m + 1; ind2++){
                
                if(word1[ind1 -1] == word2[ind2 - 1]){
                    dp[ind1][ind2] = 0 + dp[ind1 -1][ind2 -1];
                }
                else{
                    dp[ind1][ind2] = 1 + min(dp[ind1 - 1][ind2] , min(dp[ind1 -1][ind2 -1] , dp[ind1][ind2 -1]));
                }
            }
        }
        return dp[n][m];
        
    }
};