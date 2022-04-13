class Solution {
public:
    bool minimizeSubarray(vector<int> &nums, int limit, int m)
    {
        int cnt = 1;
        int sum = 0;
        
        for(int i =0; i < nums.size(); i++)
        {
            if(nums[i] > limit)
                return false;
            
            if(sum + nums[i] > limit)
            {
                cnt++;
                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }
        }
        return cnt <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(int i =0; i< nums.size(); i++)
        {
            high += nums[i];
        }
        int ans = high;
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(minimizeSubarray(nums, mid, m) == true)
            {
                ans = mid;
                high = mid -1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};