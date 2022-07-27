class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> mxl(n);
        vector<int> mxr(n);
         
        // calculate the maximum element in the LEFT
         mxl[0] = arr[0];
        for(int i = 1; i<n; i++)
        {
            mxl[i] = max(mxl[i-1],  arr[i]);
        }
        
        // calculate the maximum element in the LEFT
        mxr[n-1] = arr[n-1];
        for(int i = n -2; i>= 0; i-- )
        {
            mxr[i] = max(mxr[i+1], arr[i]);
        }
        
        // water will be store in between of mxr and mxl
        // take  min of mxr and mxl 
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