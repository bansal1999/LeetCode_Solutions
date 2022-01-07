class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;
        vector<int> ans;
        
        
        for(int i=0; i< nums1.size(); i++)
        {
            mp[nums1[i]]++;
        }
        
        for(int i =0; i< nums2.size(); i++)
        {
            int num = nums2[i];
            
            if(mp.find(num) != mp.end())
            {
                ans.push_back(num);
                mp[num]--;
                
                if(mp[num] == 0)
                    mp.erase(num);
            }
        }
        
        return ans;
    }
};