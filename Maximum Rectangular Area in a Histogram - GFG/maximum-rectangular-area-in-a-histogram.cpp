// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<int> nslIndex(long long arr[], int n)
    {
        stack<pair<long long, int>> stk;
        vector<int> v;
        
        for(int i =0; i< n; i++)
        {
            while(!stk.empty() && stk.top().first >= arr[i])
                stk.pop();
            
            stk.empty() ? v.push_back(-1) : v.push_back(stk.top().second);
            
            stk.push({arr[i], i});
        }
        
        return v;
    }
    
    vector<int> nsrIndex(long long arr[] , int n)
    {
        stack<pair<long long, int>> stk;
        vector<int> v;
        
        for(int i = n -1; i >= 0; i--)
        {
            while(!stk.empty() && stk.top().first >= arr[i])
                stk.pop();
                
            stk.empty() ? v.push_back(n) : v.push_back(stk.top().second);
            
            stk.push({arr[i] , i});
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> nsl = nslIndex(arr, n);
        vector<int> nsr = nsrIndex(arr, n);
        
        long long maxArea = INT_MIN;
        
        for(int i =0; i<n; i++)
        {
            long long width = nsr[i] - nsl[i] - 1;
            long long area = width*arr[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends