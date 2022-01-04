class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int prefix  =0;
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        mp[prefix] = 1;
        for(int i =0; i<n; i++)
        {
            prefix += nums[i];
            
            if(mp.find(prefix - k) != mp.end())
            {
                ans += mp[prefix - k];
            }
            if(mp.find(prefix) != mp.end())
            {
                mp[prefix] += 1;
            }
            else
                mp[prefix] = 1;
        }
        return ans;
    }
};