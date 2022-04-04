class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& num1, vector<int>& num2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        
        vector<vector<int>> ans;
        set<int> a1, a2;
        
        for(auto it: num1)
        {
            mp1[it]++;
        }
        
        for(auto it: num2)
        {
            mp2[it]++;
        }
        
        for(auto it: num1)
        {
            if(mp2.find(it) == mp2.end())
            {
                a1.insert(it);
            }
        }
        
        for(auto it: num2)
        {
            if(mp1.find(it) == mp1.end())
            {
                a2.insert(it);
            }
        }
        
        vector<int> vec1, vec2;
        for(auto it: a1)
        {
            vec1.push_back(it);
        }
        
        for(auto it: a2)
        {
            vec2.push_back(it);
        }
       
        ans.push_back(vec1);
        ans.push_back(vec2);
        
        return ans;
    }
};