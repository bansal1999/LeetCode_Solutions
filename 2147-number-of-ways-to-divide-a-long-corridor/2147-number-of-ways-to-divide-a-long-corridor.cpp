class Solution {
public:
    
    const int MOD = (int)1e9 + 7;
    long long dp[100001][3];
    long long helper(string &corridor, int idx, int cnt)
    {
        if(idx >= corridor.size())
            return cnt == 2;
        
        if(dp[idx][cnt] != -1)
            return dp[idx][cnt];
        
        if(cnt == 2)
        {
            if(corridor[idx] == 'P')
            {
                return dp[idx][cnt] = (helper(corridor, idx + 1, cnt) % MOD) +  (helper(corridor, idx + 1, 0) % MOD);
            }
            else
            {
                return dp[idx][cnt] = helper(corridor, idx + 1, 1) % MOD;
            }
        }
        else
        {
            return dp[idx][cnt] = helper(corridor, idx + 1, cnt + (corridor[idx] == 'S')) % MOD;
        }
    }
    
    int numberOfWays(string corridor) {
        memset(dp, -1, sizeof(dp));
        return helper(corridor, 0, 0);
    }
};