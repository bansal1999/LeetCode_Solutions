class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        
        int steps =0;
        int capCurrent = capacity;
        
        for(int i=0; i< plants.size(); i++)
        {
            if(plants[i] >  capCurrent)
            {
                capCurrent = capacity;
                steps += (2*i+1);
                
            }
            else
            {
                steps += 1;
            }
            
            capCurrent -= plants[i];
        }
        
        return steps;
        
    }
};