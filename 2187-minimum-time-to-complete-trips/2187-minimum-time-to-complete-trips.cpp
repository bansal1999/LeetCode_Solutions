class Solution {
    
    
public:
    long long tripsTakenTime(vector<int>&time, long long secs)
    {
        long long cnt =0;
        for(auto it: time)
        {
            cnt += (secs/it);
        }
        
        return cnt;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low =1, high = 1e14;
        long long ans = high;
        
        while(low <= high)
        {
            long long mid = (low + high) >> 1;
            if(tripsTakenTime(time, mid) >= totalTrips)
            {
                ans = mid;
                high = mid -1;
            }
            else
            {
                low = mid +1;
            }
        }
        
        return ans;
    }
};