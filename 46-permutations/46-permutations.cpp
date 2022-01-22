class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        helper(nums, 0, result);
        return result;
    }
    
    void helper(vector<int>& nums, int curr, vector<vector<int>> &result)
    {
        if(curr >= nums.size())
        {
            result.push_back(nums);
            return;
        }
        
        for(int i = curr; i< nums.size(); i++)
        {
            swap(nums[curr], nums[i]);
            helper(nums, curr + 1, result);
            
            swap(nums[curr], nums[i]);
        }
        
        
    }

};