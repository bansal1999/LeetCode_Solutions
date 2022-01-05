class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        unordered_map<int, int> mp;
        for(int i=0; i< s.size(); i++)
        {
            char currChar = s[i];
            if(mp.find(currChar) != mp.end())
            {
                mp[currChar] += 1;
            }
            else
                mp[currChar] = 1;
        }
        
        for(int j = 0; j< t.size(); j++)
        {
            char currChar2 = t[j];
            
            if(mp.find(currChar2) == mp.end())
                return false;
            
            if(mp.find(currChar2) != mp.end())
            {
                mp[currChar2] -= 1;
            }
            
            if(mp[currChar2] == 0)
                mp.erase(currChar2);
           
        }
        
        return mp.size() == 0;
    }
};