class Solution {
public:
    bool isPossibleBouquets(vector<int> &bloomDay, int presentDay, int m, int k)
    {
        int flr_cnt =0;
        int bou_cnt =0;
        
        for(int i =0; i< bloomDay.size(); i++)
        {
            if(bloomDay[i] <= presentDay)
            {
                flr_cnt++;
                if(flr_cnt == k)
                {
                    bou_cnt++;
                    flr_cnt =0;
                }
            }
            else
                flr_cnt = 0;
        }
        
        if(bou_cnt >= m)
            return true;
        else
            return false;
    }
    
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(isPossibleBouquets(bloomDay, mid, m, k) == true)
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