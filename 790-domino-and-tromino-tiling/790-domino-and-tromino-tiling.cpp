class Solution {
private:
    int nn;
    const int MOD = 1e9 + 7;
private:
    int f(int idx, int space, vector<vector<int>> &dp)
    {
        if(idx == nn + 1)
        {
            if(space == false)
                return 1;
            else
                return 0;
        }
        
        if(idx > nn + 1)
            return 0;
        
        if(dp[idx][space] != -1)
            return dp[idx][space];
        
        long long cnt = 0;
        if(space == true)
        {
            cnt += f(idx+1, false, dp);
            cnt += f(idx + 1, true, dp);
        }
        else
        {
            cnt += f(idx + 1, false, dp);
            cnt += f(idx+2, false, dp);
            cnt += 2*f(idx + 2, true, dp);
            
        }
        return dp[idx][space] = cnt%MOD;
    }
    
public:
    int numTilings(int n) {
        nn= n;
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(1, false, dp);
    }
};