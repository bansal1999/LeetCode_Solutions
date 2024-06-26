class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> mp;
        
        for(auto &it: magazine){
            mp[it]++;
        }
        
        for(auto &it: ransomNote){
            if(mp[it]){
                mp[it]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};