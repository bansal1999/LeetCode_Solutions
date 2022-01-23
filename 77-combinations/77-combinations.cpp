class Solution {
public:
    void helper(int n, int k, int curr, vector<vector<int>> &result, vector<int>&subset )
    {
        if(subset.size() == k )
        {
            result.push_back(subset);
            return;
        }
        
        for(int i = curr; i< n+1; i++)
        {
            subset.push_back(i);
            helper(n, k, i + 1, result, subset);
            subset.pop_back();
                
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> result;
        vector<int> subset;
        
        helper(n, k, 1, result, subset);
        return result;
    }
};