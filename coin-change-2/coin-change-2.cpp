class Solution {
public:
    
    vector<vector<int>> dp;
    
    int changeHelper(int amount, vector<int>& coins, int n)
    {
        if(n == 0)
            return 0;
        
        if(amount == 0)
            return 1;
        
        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        if(coins[n-1] > amount)
        {
             dp[n][amount] = changeHelper(amount, coins, n-1);
             return dp[n][amount];
        }
        else
        {
            dp[n][amount] = changeHelper(amount, coins, n-1) + changeHelper(amount - coins[n-1], coins, n);
            return dp[n][amount];
        }  
    }
    
    
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        if(amount == 0)
            return 1;
        
        if(n == 0)
            return 0;
        
        dp.resize(n+1,vector<int>(amount +1, -1));
        
        dp[n][amount] = changeHelper(amount, coins, n);
        
        return dp[n][amount];
        
    }
};