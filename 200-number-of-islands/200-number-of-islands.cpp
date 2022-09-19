class Solution {
public:
    int numIslands(vector<vector<char>> grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        for(int i =0; i < m; i++){
            for(int j= 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans += 1;
                    helper(grid, i, j, m, n);
                }
            }
        }
        return ans;
    }
    
    void helper(vector<vector<char>>& grid, int row , int col, int m, int n){
        if(row >= m || row < 0 || col >= n || col < 0 || grid[row][col] == '0'){
            return;
        }
        
        grid[row][col] = '0';
        
        helper(grid, row + 1, col, m, n);
        helper(grid, row - 1, col, m, n);
        helper(grid, row, col + 1, m, n);
        helper(grid, row, col - 1, m, n);
    }
    
};