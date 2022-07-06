class Solution {
public:
    bool helper(vector<int>& nums, int k, int ind,  vector<vector<int>> &dp){
        if(k == 0){
            return true;
        }
        
        if(ind == 0){
            return nums[0]==k;
        }
        
        if(dp[ind][k] != -1){
            return dp[ind][k];
        }
        
        bool notTaken = helper(nums, k, ind - 1, dp);
        bool taken  = false;
        
        if(nums[ind] <= k){
            taken = helper(nums, k - nums[ind], ind - 1, dp);
        }
        
        return dp[ind][k] = taken || notTaken;
        
    }
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        
        int k = sum/2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        if(sum % 2 == 0){
            return helper(nums, k , n-1, dp);
        }
        else{
            return false;
        }
    }
};