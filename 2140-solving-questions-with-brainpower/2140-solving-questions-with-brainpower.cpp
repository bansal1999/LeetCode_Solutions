class Solution {
public:
    long long dfs(vector<vector<int>>& Q, int idx, vector<long long>& dp)
    {
        if(idx >= Q.size())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int points = Q[idx][0];
        int jump = Q[idx][1];
        
        return dp[idx]= max(dfs(Q, idx +1, dp) , points + dfs(Q, idx + 1 + jump, dp));
    }
    
    
    
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        
        return dfs(questions, 0, dp);
    }
};