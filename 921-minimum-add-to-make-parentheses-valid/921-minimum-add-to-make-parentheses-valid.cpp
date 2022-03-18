class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0,  right = 0;
        
        for(int i =0; i< s.size(); i++)
        {
            char ch = s[i];
            if(ch == '(')
                left++;
            else if( ch == ')')
            {
                if(left > 0)
                    left--;
                else
                    right++;
            }
        }
        return left + right;
    }
};