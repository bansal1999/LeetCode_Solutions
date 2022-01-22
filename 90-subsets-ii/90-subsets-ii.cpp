class Solution {
public:
    
    vector<vector<int>> result;
    void helper(vector<int>& nums, int curr, vector<int> &subset)
    {
        result.push_back(subset);
        
        for(int i = curr; i< nums.size(); i++)
        {
            if(i > curr and nums[i-1] == nums[i])
                continue;
            
            subset.push_back(nums[i]);
            helper(nums, i +1, subset);
            
            subset.pop_back();
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        helper(nums, 0, subset);
        return result;
    }
};


// class Solution {
// public:
//     vector<vector<int>> result;
//     void solve(vector<int>& nums , int start , vector<int>& subset){
//         result.push_back(subset);
//         for(int i=start ;i<nums.size();i++){
//             if(i>start and nums[i-1] == nums[i])
//                 continue;
//             subset.push_back(nums[i]);
//             solve(nums , i+1 , subset);
//             subset.pop_back();
//         }
//     }
    
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin() , nums.end());
//         vector<int> subset;
//         solve(nums, 0 , subset);
//         return result;
//     }
// };