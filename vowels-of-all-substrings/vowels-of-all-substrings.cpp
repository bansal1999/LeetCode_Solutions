class Solution {
    bool isVowel(char t)
    {
        if(t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
            return true;
        else
            return false;
    }
    
public:
    long long countVowels(string word) {
        long long n = word.size();
        long long count =0;
        
        for(long long i=0; i<n; i++)
        {
            if(isVowel(word[i]) == true)
                count += (n-i)*(i+1);
        }
        return count;
    }
};