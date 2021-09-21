class Solution {
public:
    bool static compare(int a, int b)
    {
        return abs(a) < abs(b);
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        int n = arr.size();
        
        sort(arr.begin(), arr.end(), compare);
        
        for(int i=0; i<n ; i++)
        {
            mp[arr[i]]++;
        }
        
        for(int i=0; i<n; i++)
        {
            int twice = arr[i]*2;
            
            if(mp[arr[i]] == 0)
                continue;
            if(mp[twice] == 0)
                return false;
            
            mp[arr[i]]--;
            mp[twice]--;
        }
        return true;
    }
};