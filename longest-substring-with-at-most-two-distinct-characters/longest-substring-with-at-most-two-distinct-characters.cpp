class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int n = s.length();
        
        if(n < 3)
            return n;
        
        int left =0, right =0;
        int maxLen = 2;
        
        map<char, int> hashmap;
        
        while(right < n)
        {
            hashmap[s[right]] = right;
            right++;
            
            
            if(hashmap.size() == 3)
            {
                int index = INT_MAX;
                for(pair<char, int>element: hashmap)
                {
                    index = min(index, element.second);
                }
                
                hashmap.erase(s[index]);
                left = index+1;
            }
            
            maxLen = max(maxLen , right - left);
        }
        return maxLen;
        
        
        
    }
};