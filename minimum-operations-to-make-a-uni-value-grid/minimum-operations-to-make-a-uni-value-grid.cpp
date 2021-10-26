class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m =  grid.size(), n = grid[0].size();
        vector<int> nums;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j< n; j++)
            {
                nums.push_back(grid[i][j]);
            }
        }
        
        sort(nums.begin(), nums.end());
        
        int median = nums[nums.size() / 2];
        int res =0;
        
        for(int i= nums.size()-1; i>=0; i--)
        {
            if(abs(nums[i] - median)%x)
                return -1;
            
            res += abs(nums[i] - median)/x;
        }
        return res;
        
    }
};