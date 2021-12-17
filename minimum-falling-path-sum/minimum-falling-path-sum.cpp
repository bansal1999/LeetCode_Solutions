class Solution {
public:
    
    int helper(int n, int cr, int cc, vector<vector<int>> &matrix, vector<vector<int>> &vec)
    {
        if(cr >= n || cc >= n || cr < 0 || cc < 0)
            return 10000;
        
        if(cr == n-1)
            return matrix[cr][cc];
        
        if(vec[cr][cc] != -1)
            return vec[cr][cc];
        
        int d = matrix[cr][cc] + helper(n, cr + 1, cc, matrix, vec);
        int dl = matrix[cr][cc] + helper(n, cr + 1, cc -1, matrix, vec);
        int dr = matrix[cr][cc] + helper(n ,  cr+1, cc +1, matrix, vec);
        
        return vec[cr][cc] = min(d, min(dr, dl));
        
        
    }
    
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix[0].size();
        int ans = 10000;
        vector<vector<int>> vec (102, vector<int>(102, -1));
        
        for(int i=0; i < n; i++)
        {
            ans = min(ans, helper(n, 0, i, matrix, vec));
        }
        return ans;
    }
}; 