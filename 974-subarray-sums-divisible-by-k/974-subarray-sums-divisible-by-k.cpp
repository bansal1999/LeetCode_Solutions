class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, prefix = 0;
        unordered_map<int, int> mp;
        
        mp[prefix] = 1;
        
        for(int i =0; i< nums.size(); i++)
        {
            prefix += nums[i];
            int rem = ((prefix % k) + k)%k;  //to handle negative cases
            
            if(mp.find(rem) != mp.end())
            {
                ans += mp[rem];
                mp[rem]++;
            }
            else
                mp[rem] = 1;
        }
        return ans;
    }
};