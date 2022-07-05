class Solution {
public:
//     int lcsHelper(string text1, string text2, int ind1, int ind2, vector<vector<int>> &dp){
//         if(ind1 < 0 || ind2 < 0){
//             return 0;
//         }
        
//         if(dp[ind1][ind2] != -1){
//             return dp[ind1][ind2];
//         }
        
        
//         if(text1[ind1] == text2[ind2]){
//             return dp[ind1][ind2] = 1 + lcsHelper(text1, text2, ind1 - 1, ind2 - 1, dp);
//         }
//         else{
//             return dp[ind1][ind2] = 0 + max(lcsHelper(text1, text2, ind1 - 1, ind2, dp) ,  lcsHelper(text1, text2, ind1, ind2 -1, dp));
//         }
        
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i =0; i < n + 1; i++){
            dp[i][0] = 0;
        }
        
        for(int j = 0; j < m  +1; j++){
            dp[0][j] = 0;
        }
        
        for(int ind1 = 1; ind1 < n + 1; ind1++){
            for(int ind2 = 1; ind2 < m + 1; ind2++){
                if(text1[ind1- 1] == text2[ind2 -1]){
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else{
                    dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2] , dp[ind1][ind2 - 1]);
                }
            }
        }
        
        return dp[n][m];
    
    }
};