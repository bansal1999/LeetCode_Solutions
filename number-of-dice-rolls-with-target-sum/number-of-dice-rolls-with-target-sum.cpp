class Solution {
public:
    #define MOD 1000000007
    
    int helper(int n, int k, int target, vector<vector<int>>&vec)
    {
        if(n == 0 && target ==0)
            return 1;
        if(n ==0 && target != 0)
            return 0;
        
        if(vec[n][target] != -1)
            return vec[n][target];
        
        int ans =0;
        for(int i=1; i<= k; i++)
        {
            if(i <= target)
            {
                int tempans = helper(n-1, k,  target - i, vec);
                ans = (ans % MOD + tempans % MOD)%MOD;
            }
        }
        return vec[n][target] = ans%MOD;
    } 
    
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> vec(32, vector<int>(1001, -1));
        
        return helper(n, k, target, vec)%MOD;
        
    }
};