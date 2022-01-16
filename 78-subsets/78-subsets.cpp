class Solution {
public:
    
    void generateSubsets(vector<int>& nums, int curr, vector<int>& subset, vector<vector<int>>& powerSet)  
    {
        if(curr >= nums.size())
        {
            powerSet.push_back(subset);
            return;
        }
        
        int currVal = nums[curr];
        subset.push_back(currVal);
        generateSubsets(nums, curr + 1, subset, powerSet);
        
        subset.pop_back();
        
         generateSubsets(nums, curr + 1, subset, powerSet);
        
    }
        
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> subset;
        generateSubsets(nums, 0, subset, powerSet);
        return powerSet;
    }
};