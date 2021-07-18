class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        // using Hashmap to record history
        
        unordered_map<int, int> history;
        
        int pos =0, maxVal =0;
        
        // traverse the brick level by level
        
        for(int i =0; i< wall.size(); i++)
        {
            pos =0;
            for(int j=0; j < wall[i].size()-1; j++)
            {
                pos += wall[i][j];
                history[pos]++;
                maxVal = max(maxVal, history[pos]);
            }
        }
        
        return wall.size() - maxVal;
    }
};