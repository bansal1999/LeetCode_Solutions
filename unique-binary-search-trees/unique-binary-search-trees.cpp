class Solution {
public:
    int helper(int n, vector<int>& vec)
    {
        if(n <= 1)
            return 1;
        
         int curr = n;
        
        if(vec[curr] != -1)
            return vec[curr];
        
        int catalan = 0;
        
        for(int i=0; i< n; i++)
        {
            catalan += helper(i, vec)*helper(n - i - 1, vec);
        }
        vec[curr] = catalan;
        return vec[curr];
    }
    
    int numTrees(int n) {
        vector<int> vec(101, -1);
        
        return helper(n, vec);
    }
};