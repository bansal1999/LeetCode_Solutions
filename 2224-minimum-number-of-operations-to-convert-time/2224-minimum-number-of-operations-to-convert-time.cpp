class Solution {
public:
    int convertTime(string current, string correct) {
        string h1 ="";
        string h2 = "";
        string m1 = "";
        string m2 = "";
        
        h1 += current[0];
        h1 += current[1];
        
        m1 += current[3];
        m1 += current[4];
        
        h2 += correct[0];
        h2 += correct[1];
        
        m2 += correct[3];
        m2 += correct[4];
        
        
        int min1 = stoi(h1)*60 + stoi(m1);
        int min2 = stoi(h2)*60 + stoi(m2);
        
        int count = 0;
        
        while(min2 > min1)
        {
            if((min2 - min1) >= 60)
            {
                min1 += 60;
                count++;
            }
            else if((min2 - min1) >= 15)
            {
                min1 += 15;
                count++;
            }
            else if((min2 - min1) >= 5)
            {
                min1 += 5;
                count++;
            }
            else
            {
                count += (min2 - min1);
                min1 = min1 + (min2 - min1);
            }
        }
        return count;
    }
};