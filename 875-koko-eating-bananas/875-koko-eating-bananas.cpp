class Solution {
public:
    int requiredHours(vector<int> &piles, int k)
    {
        int hrs =0;
        for(auto it: piles)
        {
            hrs += (it/k);
            
            if(it % k != 0)
                hrs++;
        }
        return hrs;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        while(low < high)
        {
            int mid = low + (high - low)/2;
            
            int ans = requiredHours(piles, mid);
            
            if(ans > h)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return high;
    }
};