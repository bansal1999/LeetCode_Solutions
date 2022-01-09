class Solution {
public:
     string capitalizeTitle(string s) {
        
        int i=0,n=s.length();
        
        while(i<n){
            int j=i;
            while(j<n and s[j]!=' ')j++;
            if((j-i) >2){
                s[i]=toupper(s[i]);
                i++;
            }
            while(i!=j){
                s[i]=tolower(s[i]);
                i++;
            }
            i=j+1;
        }
        
        return s; 
    }
};