class Solution {
public:
    
    int robHelper(vector<int> nums, int start, int end)
    {
        vector<int> dp(end-start, 0);
        
        dp[0] = nums[start];
        dp[1] = max(dp[0], nums[start + 1]);
        
        
        for(int i = start +2; i< end; i++)
        {
            dp[i-start] = max(dp[i-start -1], nums[i]+dp[i-start -2] ) ;
        }
        
        return dp[dp.size() -1 ];
    }
    
    
    
    
    
    
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)
        {
            return nums[0];
        }
        
        if(n==2)
        {
            return max(nums[0], nums[1]);
        }
        
        return max(robHelper(nums, 0, n-1), robHelper(nums, 1, n));
        
    }
    
    
};