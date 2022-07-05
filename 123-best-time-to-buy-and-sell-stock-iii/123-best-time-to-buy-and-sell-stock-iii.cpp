class Solution {
public:
    int helper(vector<int>& prices, int n, int ind, int buy, int txn, vector<vector<vector<int>>> &dp){
        
        if(ind == n || txn == 0){
            return 0;
        }
        
        if(dp[ind][buy][txn] != -1){
            return dp[ind][buy][txn];
        }
        
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + helper(prices, n, ind + 1, 0, txn, dp), 0 + helper(prices, n, ind + 1, 1, txn, dp));
        }
        else{
            profit = max(prices[ind] + helper(prices, n, ind + 1, 1, txn - 1, dp) , 0 + helper(prices, n, ind + 1, 0, txn , dp));
        }
        
        return dp[ind][buy][txn] = profit;
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
        int ans = helper(prices, n, 0, 1, 2, dp);
        return ans;
    }
};