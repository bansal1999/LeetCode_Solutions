class Solution {
public:
    int helper(vector<vector<char>> &matrix, int cr, int cc, int m, int n, unordered_map<string , int> &mp)
    {
        if(cr <0  || cc < 0 || cr >= m || cc >= n || matrix[cr][cc] == '0')
            return 0;
        
        string currkey = to_string(cr) + "_" + to_string(cc);
        if(mp.find(currkey) != mp.end())
            return mp[currkey];
        
        int right = 1 + helper(matrix, cr, cc +1, m , n, mp);
        int down = 1 + helper(matrix, cr + 1, cc, m, n, mp);
        int downRight = 1 + helper(matrix, cr +1 ,  cc + 1, m, n, mp);
        return mp[currkey] = min(right, min(down, downRight));
        
    }
    
    
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp;
        int ans =0;
        
        for(int i=0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(matrix[i][j] == '1')
                    ans = max(ans, helper(matrix, i, j, m, n, mp));
            }
        }
        
        return ans*ans;
    }
};