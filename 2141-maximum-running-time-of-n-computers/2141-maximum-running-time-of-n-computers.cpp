class Solution {
public:
    bool checkMid(long long mid, vector<int>& batteries, int n)
    {
        long long total = mid*n;
        long long cnt = 0;
        
        for(auto &it: batteries)
        {
            cnt += min((long long)it, mid);
        }
        return cnt >= total;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        
        for(auto &it: batteries)
            sum += it;
        
        long long low =0, high = sum;
        long long ans = 0;
        
        while(low <= high)
        {
            long long mid = (low + high )/2;
            
            if(checkMid(mid, batteries, n))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};