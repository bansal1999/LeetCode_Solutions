class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int refillCnt =0, aliceCap = capacityA, bobCap = capacityB;
        
        int i=0, j = plants.size() -1;
        
        //if alice and bob are on the same plant
        
        while(i <= j)
        {
            if(i == j)
            {
                if(aliceCap >= bobCap)
                {
                    if(plants[i] > aliceCap)
                    {
                        refillCnt++;
                    }
                }
                else
                {
                    if(plants[i] > bobCap)
                    {
                        refillCnt++;
                    }
                }
                break;
            }
            
            if(plants[i] > aliceCap)
            {
                refillCnt++;
                aliceCap = capacityA;
            }
            
            if(plants[j] > bobCap)
            {
                refillCnt++;
                bobCap = capacityB;
            }
            
            aliceCap -= plants[i];
            bobCap -= plants[j];
            
            i++;
            j--;
            

        }
        return refillCnt;
        
    }
};