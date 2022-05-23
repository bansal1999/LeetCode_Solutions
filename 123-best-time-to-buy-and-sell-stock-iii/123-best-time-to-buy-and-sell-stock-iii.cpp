class Solution {
// private:
//     int helper(int ind, int buy, int txn, vector<int>&prices, int n, vector<vector<vector<int>>> &dp)
//     {
//         if(ind == n || txn == 0)
//             return 0;
        
//         if(dp[ind][buy][txn] != -1)
//             return dp[ind][buy][txn];
        
//         if(buy == 1)
//         {
//             return dp[ind][buy][txn] = max(-prices[ind] + helper(ind+1, 0, txn, prices, n, dp) , 0 + helper(ind + 1, 1, txn, prices, n, dp));
//         }
//         else
//             return dp[ind][buy][txn] = max(prices[ind] + helper(ind + 1, 1, txn -1, prices, n, dp) , 0 + helper(ind + 1, 0, txn, prices, n, dp));
//     }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3, 0)));
        
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int txn = 1; txn <=2; txn++)
                {
                    if(buy == 1)
                    {
                        dp[ind][buy][txn] = max(-prices[ind] + dp[ind+1][0][txn] , 0 + dp[ind+1][1][txn]);
                    }
                    else
                    {
                        dp[ind][buy][txn] = max(prices[ind] + dp[ind+ 1][1][txn-1] , 0 + dp[ind+1][0][txn]);
                    }
                    
                }
            }
        }
        
        return dp[0][1][2];
    }
};