class Solution {
public:
    bool maximizeSubarray(vector<int> &sweetness, int limit, int k)
    {
        // int cnt = 0;
        int sum = 0;
        
        for(int i =0; i<sweetness.size(); i++)
        {
            sum += sweetness[i];
            
            if(sum >= limit)
            {
                // cnt++;
                k--;
                sum =0;
            }
        }
        return k < 0;
    }

    int maximizeSweetness(vector<int>& sweetness, int k) {
        int low = *min_element(sweetness.begin(), sweetness.end()); 
        int high= 0;
        for(int i =0; i< sweetness.size(); i++)
        {
            high += sweetness[i];
        }

        int ans = low;
        while(low <= high)
        {
            int mid = low  + (high - low)/2;
            
            if(maximizeSubarray(sweetness, mid, k) == true)
            {
                ans = mid;
                low = mid+1 ;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};