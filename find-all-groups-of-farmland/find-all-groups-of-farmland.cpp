class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>> ans;
        int row = land.size();
        int col = land[0].size();
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j< col; j++)
            {
                if(land[i][j] == 1)
                {
                    int start_i = i;
                    int start_j = j;
                    
                    while(start_i < row && land[start_i][start_j] == 1)
                    {
                        start_i++;
                    }
                    start_i = start_i-1;
                    
                    while(start_j < col && land[start_i][start_j] == 1)
                    {
                        start_j++;
                    }
                    start_j = start_j - 1;
                    
                    ans.push_back({i, j, start_i, start_j});
                    
                    
                    for(int k = i; k<= start_i; k++)
                    {
                        for(int l = j; l<= start_j; l++)
                        {
                            land[k][l] = -1;
                        }
                    }
                    
                    
                }
            }
        }
        return ans;
    }
};