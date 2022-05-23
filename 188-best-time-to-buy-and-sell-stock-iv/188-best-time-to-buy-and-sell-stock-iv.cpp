class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(k+1, 0)));
        
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int txn = 1; txn <=k; txn++)
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
        return dp[0][1][k];
    }
};