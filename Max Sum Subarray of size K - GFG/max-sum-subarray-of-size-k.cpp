// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &arr , int N){
        // code here 
        
        int res = 0;
        for(int i =0; i< K; i++)
        {
            res += arr[i];
        }
        
        int currSum = res;
        
        for(int i = K; i< N; i++)
        {
            currSum += arr[i] - arr[i-K];
            res = max(res, currSum);
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends