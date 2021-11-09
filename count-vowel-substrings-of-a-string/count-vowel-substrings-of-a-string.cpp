class Solution {
    
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    int countAtmostKVowel(string s, int k)
    {
        int i=0;
        int n = s.size();
        unordered_map<char, int> mp;    
        int cnt =0;
        
        for(int j=0; j<n; j++)
        {
            if(!isVowel(s[j]))
            {
                mp.clear();
                i = j+1;
                continue;
            }
            mp[s[j]]++;
            
            while(mp.size() > k)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            
            cnt += (j-i + 1);
            
        }
        return cnt;
    }
    
public:
    int countVowelSubstrings(string s) {
        
        return countAtmostKVowel(s, 5) - countAtmostKVowel(s, 4);
       
    }
};