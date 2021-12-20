class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
       long int ans = prices.size();
       long int cnt =0;
        for( long int i=1; i< prices.size(); i++)
        {
            if(prices[i-1] - prices[i] == 1)
            {
                cnt++;
            }
            else
                cnt = 0;
            ans += cnt;
        }
        return ans;
        
    }
};