class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> mxl(n);
        vector<int> mxr(n);
        
        mxl[0] = arr[0];
        
        for(int i = 1; i<n; i++)
        {
            mxl[i] = max(mxl[i-1],  arr[i]);
        }
        
        mxr[n-1] = arr[n-1];
        for(int i = n -2; i>= 0; i-- )
        {
            mxr[i] = max(mxr[i+1], arr[i]);
        }
        
        vector<int> water(n);
        for(int i =0; i< n; i++)
        {
            water[i] = min(mxl[i], mxr[i]) - arr[i];
        }
        
        long long sum =0;
        for(int i =0; i< n; i++)
        {
            sum += water[i];
        }
        
        return sum;
        
    }
};