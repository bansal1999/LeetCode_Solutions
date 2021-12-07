class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>ans (n, -1);
        
        long long sum =0;
        int len = 2*k +1;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(i >= len)
                sum -= nums[i - len];
            
            if( i >= len - 1)
                ans[i-k] = sum /len;
                
                
        }
        
        return ans;
    }
};

