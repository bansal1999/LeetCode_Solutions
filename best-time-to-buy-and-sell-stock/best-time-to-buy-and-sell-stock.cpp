class Solution {
public:
    int bestTrans(vector<int>&prices, int currIdx, bool canBuy, int trans, vector<vector<vector<int>>>&vec)
    {
        if(currIdx >= prices.size())
            return 0;
        
        if(trans <= 0)
            return 0;
        
        if(vec[currIdx][canBuy][trans] != -1)
            return vec[currIdx][canBuy][trans];
        
        if(canBuy)
        {
            int idle = bestTrans(prices, currIdx + 1, canBuy, trans, vec);
            int buy = -prices[currIdx] + bestTrans(prices, currIdx + 1, !canBuy, trans, vec);
            return vec[currIdx][canBuy][trans] = max(idle, buy);
        }
        else
        {
            int idle = bestTrans(prices, currIdx + 1, canBuy, trans, vec);
            int sell = prices[currIdx] + bestTrans(prices, currIdx + 1, canBuy, trans - 1, vec);
            return vec[currIdx][canBuy][trans] = max(idle, sell);
        }
        
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> vec(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return bestTrans(prices, 0, 1, 1, vec);
    }
};