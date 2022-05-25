class Solution {
// private:
//     int helper(int ind, int prev, vector<int>& arr, int n, vector<vector<long long>> &dp)
//     {
//         if(ind == n)
//             return 0;

//         if(dp[ind][prev+1] != -1)
//             return dp[ind][prev+1];

//         int len = 0 + helper(ind + 1, prev, arr, n, dp);

//         if(prev == -1 || arr[ind] > arr[prev])
//             len = max(len, 1 + helper(ind+1, ind, arr, n, dp));

//         return dp[ind][prev+1] = len;
//     }
    
public:
    int lengthOfLIS(vector<int>& arr) {
        
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int prev = ind -1; prev >= -1; prev--)
            {
                int len = 0 + dp[ind+1][prev+1];
                
                if(prev == -1 || arr[ind] > arr[prev])
                {
                    len = max(len, 1 + dp[ind+1][ind+1]);
                }
                
                dp[ind][prev+1] = len;
            }
        }
        return dp[0][-1+1];
        
    }
};