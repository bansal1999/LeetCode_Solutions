class Solution {
public:
    void totalways(vector<int>& candidates, int target, vector<vector<int>>&ans,
        vector<int>&vec, int curr)
    {
        if(target == 0)
        {
            ans.push_back(vec);
            return;
        }
        
        if(curr >= candidates.size())
            return;
        
        int currVal = candidates[curr];
        
        if(target >= currVal)
        {
            vec.push_back(currVal);
            
            totalways(candidates, target - currVal, ans, vec, curr );
            
            vec.pop_back();
        }
        
        totalways(candidates, target, ans, vec, curr + 1);
        
        
    }
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        totalways(candidates, target, ans, vec, 0);
        return ans;  
    }
};