class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        char r1, r2, c1, c2;
        
        r1 = s[0];
        c1 = s[1];
        r2 = s[3];
        c2 = s[4];
        
        
       for(char i = r1; i<= r2; i++)
       {
           for(int j = c1; j <= c2; j++)
           {
               string temp;
               temp += i;
               temp+= j;
               ans.push_back(temp);
           }
       }
        
       return ans;
    }
};