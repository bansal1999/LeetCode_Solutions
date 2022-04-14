class Solution {
public:
    bool isPossible(vector<int> &dist, double hour, int mid)
    {
        double time = 0;
        for(int i =0; i < dist.size()-1; i++)
        {
            time += ceil((double)dist[i]/mid);
        }
        time += ((double)dist.back()/mid);
        
        if(time <= hour)
            return true;
        else
            return false;
    }
    
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int low = 1;
        int high = 1e9;
        int ans = -1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(isPossible(dist, hour, mid) == true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};