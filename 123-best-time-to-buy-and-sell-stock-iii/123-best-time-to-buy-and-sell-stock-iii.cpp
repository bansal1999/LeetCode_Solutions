class Solution {
private:
    int helper(int ind, int buy, int txn, vector<int>&prices, int n, vector<vector<vector<int>>> &dp)
    {
        if(ind == n || txn == 0)
            return 0;
        
        if(dp[ind][buy][txn] != -1)
            return dp[ind][buy][txn];
        
        if(buy == 1)
        {
            return dp[ind][buy][txn] = max(-prices[ind] + helper(ind+1, 0, txn, prices, n, dp) , 0 + helper(ind + 1, 1, txn, prices, n, dp));
        }
        else
            return dp[ind][buy][txn] = max(prices[ind] + helper(ind + 1, 1, txn -1, prices, n, dp) , 0 + helper(ind + 1, 0, txn, prices, n, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));
        return helper(0, 1, 2, prices, n, dp);
    }
};