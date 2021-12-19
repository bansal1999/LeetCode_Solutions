class Solution {
public:
    bool check(string word)
    {
        int i =0;
        int j = word.size() - 1;
        
        while(i < j)
        {
            if(word[i++] != word[j--])
            {
                return false;
            }
        }
        return true;
    }
    
    
    
    string firstPalindrome(vector<string>& words) {
        
        for(int i=0; i< words.size(); i++)
        {
            if(check(words[i]))
                return words[i];
        }
        
        return "";
        
        
    }
};