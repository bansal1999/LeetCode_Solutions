class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int ans =0, distinctCnt =0, release = 0;
        unordered_map<int, int> mp;
        
        for(int i =0; i<nums.size(); i++)
        {
            int currChar = nums[i];
            
            if(mp.find(currChar) != mp.end())
            {
                mp[currChar] += 1;
            }
            else
            {
                mp[currChar] = 1;
                distinctCnt += 1;
            }
            
            while(release <= i && distinctCnt > k)
            {
                int disChar = nums[release];
                mp[disChar] -= 1;
                release += 1;
                
                if(mp[disChar] == 0)
                {
                    mp.erase(disChar);
                    distinctCnt -= 1;
                }
            }
            
            ans += (i - release + 1);
                
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};