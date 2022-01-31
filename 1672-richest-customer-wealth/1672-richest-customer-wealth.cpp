class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxSum =0;
        for(int i =0; i< accounts.size(); i++)
        {
            int rowSum =0;
            for(int j =0; j< accounts[0].size(); j++)
            {
                rowSum += accounts[i][j];
            }
            maxSum = max(maxSum, rowSum);
        }
        return maxSum;
    }
};