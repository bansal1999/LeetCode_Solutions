class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        sort(items.begin(), items.end());
        
        int n = items.size();
        for(int i=0; i< n; i++)
        {   
            if(i==0)
                continue;
            items[i][1] = max(items[i-1][1], items[i][1]);
        }
        
        vector<int> ans;
        for(auto &priceReq : queries)
        {
            vector<int> dummy(2);
            dummy[0]= priceReq;
            dummy[1]= INT_MAX;
            
            int index = upper_bound(items.begin(), items.end(), dummy) - items.begin();
            index--;
            
            if(index >= 0)
            {
                ans.push_back(items[index][1]);
            }
            else
            {
                ans.push_back(0);
            }
            
        }
        return ans;
    }
};