class Solution {
public:
    set<vector<int>> ans;
    
    void helper(vector<int> &nums, int curr)
    {
        if(curr >= nums.size())
        {
            ans.insert(nums);
            return;
        }
        
        for(int i = curr; i< nums.size(); i++)
        {
            swap(nums[curr], nums[i]);
            helper(nums, curr +1);
            swap(nums[curr], nums[i]);
        }
    }
   
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        helper(nums, 0);
        vector<vector<int>> vec(ans.begin(), ans.end());
        return vec;
    }
};