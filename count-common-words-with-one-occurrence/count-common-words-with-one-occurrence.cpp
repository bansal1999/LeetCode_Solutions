class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp1, mp2;
        
        for(int i=0; i<words1.size(); i++)
        {
            mp1[words1[i]]++;
        }
        int cnt =0;
        for(int i =0; i<words2.size(); i++)
        {
            mp2[words2[i]]++;
        }
        
        for(auto it: words1)
        {
           
            if(mp1[it] == 1 && mp2[it] == 1)
                cnt++;
                
        }
        return cnt;
            
    }
};