class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freqs(26, 0);
        
        for(int i =0; i< s.size(); i++)
        {
            freqs[s[i] - 'a']++;
        }
        
        for(int i =0; i< t.size(); i++)
        {
            freqs[t[i] - 'a']--;
        }
        
        int ans =0;
        for(int i =0; i< 26; i++)
        {
           if(freqs[i] > 0)
               ans += freqs[i];
        }
        
        return ans;
        
    }
};