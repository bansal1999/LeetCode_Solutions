class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        
        if(n < (k+1))
            return n;
        
        int left =0, right =0;
        int maxLen = k;
        
        map<char, int> hashmap;
        
        while(right < n)
        {
            hashmap[s[right]] = right;
            right++;
            
            
            if(hashmap.size() == (k+1))
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