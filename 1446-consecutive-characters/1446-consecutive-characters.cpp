class Solution {
public:
    int maxPower(string s) {
        char prev = s[0];
        int cnt = 0;
        int ans = 0;
        
        for(auto &it: s)
        {
            if(it == prev)
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
            ans = max(ans, cnt);
            prev = it;
        }
        
        return ans;
    }
};