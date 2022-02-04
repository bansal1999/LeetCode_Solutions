class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.begin(), cost.end(), greater<int>());
        int n = cost.size();
        int totalCost = 0;
        
        for(int i =0; i< n; i++)
        {
            if(i % 3 == 2)
                continue;
            
            totalCost += cost[i];
        }
        
        return totalCost;
        
        
    }
};