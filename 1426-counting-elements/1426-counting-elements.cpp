class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int>mp;
        int cnt =0;
        
        for(int i =0; i< arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        for(int i = 0; i< arr.size(); i++)
        {
            int num = arr[i];
            
            if(mp.find(num + 1) != mp.end())
            {
                cnt++;
            }
        }
        return cnt;
    }
};