class Solution {
public:
//     bool helper(vector<int>& nums, int k, int ind,  vector<vector<int>> &dp){
//         if(k == 0){
//             return true;
//         }
        
//         if(ind == 0){
//             return nums[0]==k;
//         }
        
//         if(dp[ind][k] != -1){
//             return dp[ind][k];
//         }
        
//         bool notTaken = helper(nums, k, ind - 1, dp);
//         bool taken  = false;
        
//         if(nums[ind] <= k){
//             taken = helper(nums, k - nums[ind], ind - 1, dp);
//         }
        
//         return dp[ind][k] = taken || notTaken;
        
//     }
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        
        int k = sum/2;
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        if(sum % 2 == 1){
            return false;
        }
        else{
            
            for(int i =0; i < n; i++){
                dp[i][0] = 1;
            }
            
            if(nums[0] <= k)
                dp[0][nums[0]] = 1;
            
            for(int ind = 1; ind < n; ind++){
                for(int target = 1; target <= k; target++){
                    bool nottaken = dp[ind - 1][target];
                    
                    bool taken  = false;
                    
                    if(nums[ind] <= target){
                        taken = dp[ind-1][target - nums[ind]];
                    }
                    
                    dp[ind][target] = taken || nottaken;
                }
            }
            
            return dp[n-1][k];
            
        }
    }
};