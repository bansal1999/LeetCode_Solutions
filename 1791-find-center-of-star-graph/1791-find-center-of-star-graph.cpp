class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        unordered_map<int, int> mp;
        int n = edges.size();
        int center;
        
        for(auto &it: edges)
        {
            mp[it[0]]++;
            mp[it[1]]++;
        }
        
        for(auto &itr: mp)
        {
            if(itr.second == n)
            {
                center = itr.first;
                break;
            }
        }
        
        return center;
    }
};