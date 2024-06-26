class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = 100000;
        
        int ans = high;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            int cnt  = 0;
            
            for(auto it: quantities)
            {
                cnt += it/mid;
                if(it % mid)
                    cnt += 1;
                
            }
            if(cnt <= n )
            {
                ans = mid;
                high = mid -1 ;
            }
            else
                low = mid +1;  
        }
        return ans;
    }
};