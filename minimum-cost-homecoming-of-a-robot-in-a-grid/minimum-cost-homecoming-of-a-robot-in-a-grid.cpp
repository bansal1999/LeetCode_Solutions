class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        
        int r1 = min(startPos[0], homePos[0]);
        int r2 = max(startPos[0], homePos[0]);
        
        int c1 = min(startPos[1], homePos[1]);
        int c2 = max(startPos[1], homePos[1]);
        
        int costs = 0;
        
        if(startPos[0] == r1)
            for(int i = r1 + 1; i<= r2; i++)
                costs += rowCosts[i];
        else
            for(int i = r1; i<= r2-1; i++)
                costs += rowCosts[i];
        
        if(startPos[1] == c1)
            for(int i = c1 + 1; i<= c2; i++)
                costs += colCosts[i];
        else
            for(int i = c1; i<= c2-1; i++)
                costs += colCosts[i];
                
        return costs;
    }
};