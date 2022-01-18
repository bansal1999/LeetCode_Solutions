class Solution {
public:
        bool isValid(int currRow, int currCol, vector<vector<char>>&grid, int n)
    {
        return isRowValid(currRow, grid, n) && isColValid(currCol, grid, n) && isDiagValid(currRow, currCol, grid, n);
    }
    
    
    bool isRowValid(int currRow, vector<vector<char>> &grid, int n)
    {
        for(int j =0; j< n; j++)
        {
            if(grid[currRow][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    
    bool isColValid(int currCol, vector<vector<char>> &grid, int n)
    {
        for(int i =0; i< n; i++)
        {
            if(grid[i][currCol] == 'Q' )
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool isDiagValid(int currRow, int currCol, vector<vector<char>> &grid, int n)
    {
        int i = currRow;
        int j = currCol;
        
        //checking the 1st digonal (upper left)
        while(i >= 0 && j >= 0)
        {
            if(grid[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j--;
        }
        
        //2nd diagonal (upper right)
        i = currRow;
        j = currCol;
        while(i >= 0 && j< n)
        {
            if(grid[i][j] == 'Q')
                return false;
            
            i--;
            j++;
        }
        
        
        //3rd Diagonal (lower left)
        i = currRow;
        j = currCol;
        while(i < n && j >= 0)
        {
            if(grid[i][j] == 'Q')
                return false;
            
            i++;
            j--;
        }
        
        //4th diagonal (lower right)
        i = currRow;
        j = currCol;
        while(i < n && j < 0)
        {
            if(grid[i][j] == 'Q')
                return false;
            
            i++;
            j++;
        }

        return true;

    }
    
    vector<string> populate(vector<vector<char>> &grid, int n)
    {
        vector<string> vec;
        for(int currRow =0; currRow < n; currRow++)
        {
            string temp = "";
            for(int currCol =0; currCol < n; currCol ++)
            {
                temp += grid[currRow][currCol];
            }
            vec.push_back(temp);
        }
        
        return vec;
    }
    
    
    
    
    void solve(vector<vector<char>> &grid, int currRow, int n, vector<vector<string>> &ans)
    {
        if(currRow == n)
        {
            vector<string> tempans = populate(grid, n);
            ans.push_back(tempans);
            return;
        }
        
        for(int currCol = 0; currCol < n; currCol++)
        {
            if(isValid(currRow, currCol, grid, n))
            {
                grid[currRow][currCol] = 'Q';
                solve(grid, currRow + 1, n, ans);
                
                //backtracking the changes done 
                grid[currRow][currCol] = '.';
            }
        }
        return;
    }
    
    
    
    int totalNQueens(int n) {
         vector<vector<string>> ans;
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        solve(grid, 0, n, ans);
        return ans.size();
    }
};