class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        set<int>ans;
        
        for(int i=0; i< arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.insert(it->second);
        }
        
        return ans.size() == mp.size();
    }
};