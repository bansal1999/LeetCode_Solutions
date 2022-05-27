class Solution {
private:
    bool isPalindrome(int i, int j, string &str)
    {
        while(i < j)
        {
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int helper(int i, int n, string str, vector<int> &dp)
    {
        if(i == n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int minCost = INT_MAX;
        
        for(int j = i; j<n; j++)
        {
            if(isPalindrome(i, j, str))
            {
                int cost = 1 + helper(j+1, n, str, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
    
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return helper(0, n, s, dp) -1;
    }
};