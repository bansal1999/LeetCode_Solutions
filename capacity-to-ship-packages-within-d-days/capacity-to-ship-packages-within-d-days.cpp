class Solution {
public:
    
    bool ifPossible(int minWeight, vector<int>& weights, int days )
    {
        int trips=1, curr_cap = 0;
        for(int i = 0; i< weights.size(); i++)
        {
            
            if( curr_cap + weights[i] <= minWeight)
            {
                curr_cap += weights[i];
            }
            else
            {
                trips++;
                //curr_cap = minWeight;
                curr_cap = weights[i];
                
                
            }
        }
        return (trips) <= days;
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int totalSum =0, maxSum = weights[0];
        
        for(int i=0; i< weights.size(); i++)
        {
            totalSum+= weights[i];
            maxSum = max(maxSum, weights[i]);
        }
        int lo = maxSum, hi = totalSum, mid;
        
        while(lo < hi)
        {
            mid = lo + ((hi - lo)/2);
            
            if(ifPossible(mid, weights, days))
            {
                hi = mid;
            }
            else
                lo = mid+1;
        }
        
        return lo;
        
    }
};