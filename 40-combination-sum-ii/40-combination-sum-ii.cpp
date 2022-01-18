class Solution {
public:
    void solve(vector<int> &candidates, int target, int currIdx, set<vector<int>> &ans, vector<int> &subset)
    {
        if(target == 0)
        {
            ans.insert(subset);
            return;   
        }
        
        if(currIdx >= candidates.size())
        {
            return;
        }
        
        int currVal = candidates[currIdx];
        if(target >= currVal)
        {
            subset.push_back(currVal);
            solve(candidates, target - currVal, currIdx + 1, ans, subset);  
            subset.pop_back();
        }
        
        while(currIdx + 1 <  candidates.size() && candidates[currIdx] == candidates[currIdx + 1])
        {
            currIdx++;
        }
        
        solve(candidates, target, currIdx + 1, ans, subset);
        
    }
    
 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        set<vector<int>> ans;
        sort(candidates.begin(), candidates.end());

        vector<int> subset;
        solve(candidates, target, 0, ans, subset);
        vector<vector<int>> numbers(ans.begin(), ans.end());
        return numbers;
    }
};