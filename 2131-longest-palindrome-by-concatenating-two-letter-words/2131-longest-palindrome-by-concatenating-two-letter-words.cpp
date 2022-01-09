class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans =0;
        unordered_map<string, int> mp;
        
        for(auto &it: words)
        {
            string rev = it;
            reverse(rev.begin(), rev.end());
            
            if(mp[rev] > 0)
            {
                ans += 4;
                mp[rev]--;
            }
            else
            {
                mp[it]++;
            }
        }
        
        for(auto &it2: mp)
        {
            string wd = it2.first;
            int cnt = it2.second;
            
            if(wd[0] == wd[1] && cnt > 0)
            {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};