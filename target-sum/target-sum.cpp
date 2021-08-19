class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        
        int sum =0;
        int n = nums.size();
        int subsetSum =0;
        
     
        
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
        }
        
        if(sum < target || (sum + target) % 2 != 0)
            return 0;
        
        subsetSum = (sum + target)/2;
        
        int dp[n+1][subsetSum + 1];
        
        dp[0][0] = 1;
        
        //initialize the table
        for(int i=1; i<= n; i++)
        {
            dp[i][0] = 1;
        }
        for(int j=1; j<= subsetSum; j++)
        {
            dp[0][j] =0;
        }

        
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<= subsetSum; j++ )
            {
                if(nums[i-1] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j- nums[i-1]];
                }
            }
        }
        
        return dp[n][subsetSum];
        
    }
};