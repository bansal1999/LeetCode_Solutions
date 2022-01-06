class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            int complement = target - nums[i];
            
            if(mp.find(complement) != mp.end())
            {
                return ans = {i, mp[complement]};
            }
            else
                mp[nums[i]] = i;
        }
        return ans;
        
    }
};