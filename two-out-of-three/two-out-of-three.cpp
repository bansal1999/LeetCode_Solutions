class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        
        vector<int> ans;
        set<int> s, s1, s2;
        
        for(auto i :nums1)
        {
            s.insert(i);
        }
        for(auto i: nums2)
        {
            s1.insert(i);
        }
        for(auto i: nums3)
        {
            s2.insert(i);
        }
        
        unordered_map<int, int> mp;
        
        for(auto i : s)
        {
            mp[i]++;
        }
        for(auto i : s1)
        {
            mp[i]++;
        }
        for(auto i : s2)
        {
            mp[i]++;
        }
        
        for(auto i : mp)
        {
            if(i.second >= 2)
            {
                ans.push_back(i.first);
            }
        }
        
        return ans;
            
        
        
    }
};