class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int prefix  =0;
        
        int ans =0;
        mp[prefix] = -1;
        for(int i =0; i<n; i++)
        {
            int currVal = nums[i];
            
            if(currVal == 0)
            {
                prefix += -1;
            }
            else
                prefix += 1;
            
            if(mp.find(prefix) != mp.end())
            {
                int temp = i - mp[prefix];
                ans = max(ans, temp);
            }
            else
                mp[prefix] = i;
            
        }
        
        return ans;
        
        
        
    }
};