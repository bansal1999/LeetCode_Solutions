class Solution {
public:
    int helper(int ind, int color, vector<vector<int>>& costs,  vector<vector<int>> &dp )
    {
        if(ind == costs.size())
            return 0;
        
        if(dp[ind][color] != -1)
            return dp[ind][color];
        
        int totalCost = costs[ind][color];
        
        if(color == 0)
        {
            totalCost += min(helper(ind +1, 1, costs, dp) , helper(ind +1, 2, costs, dp));
        }
        if (color == 1)
        {
            totalCost += min(helper(ind +1, 0, costs, dp) , helper(ind +1, 2, costs, dp));
        }
        if (color == 2)
        {
            totalCost += min(helper(ind +1, 1, costs, dp ) , helper(ind +1, 0, costs, dp));
        }
        
         return dp[ind][color] = totalCost ;
        
    }
    
    int minCost(vector<vector<int>>& costs) {
        
        vector<vector<int>> dp(costs.size(), vector<int>(3, -1));
        
        return min (helper(0, 0, costs, dp) , min(helper(0, 1, costs, dp) , helper(0, 2, costs, dp)));
    }
};