class Solution {
public:
    string capitalizeTitle(string title) {
        int i =0, n = title.size();
        
        while(i < n)
        {
            int j = i;
            
            while(j < n && title[j] != ' ')
            {
                j++;
            }
            
            
            if((j - i) > 2 )
            {
                title[i] = toupper(title[i]);
                i++;
            }
            
            while(i != j)
            {
                title[i] = tolower(title[i]);
                i++;
            }
            i = j +1;
        }
        
        return title;
    }
};