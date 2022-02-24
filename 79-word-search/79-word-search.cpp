class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int row = board.size();
        int col = board[0].size();
        
        for(int i =0; i< row; i++)
        {
            for(int j =0; j < col; j++)
            {
                if(board[i][j] == word[0])
                    if(dfs(board, row, col, i, j, 0, word) == true)
                        return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int row, int col, int currow, int curcol, int curidx, string word)
    {
        if(curidx == word.size())
            return true;
        
        if(currow < 0 || currow >= row || curcol <0 || curcol >= col || board[currow][curcol] != word[curidx])
            return false;
        
        board[currow][curcol] = '0';
        
        if(dfs(board, row, col, currow + 1, curcol, curidx + 1, word) == true)
            return true;
        
        if(dfs(board, row, col, currow - 1, curcol, curidx + 1, word) == true)
            return true;
        
        if(dfs(board, row, col, currow, curcol + 1, curidx + 1, word) == true)
            return true;
        
        if(dfs(board, row, col, currow, curcol - 1, curidx + 1, word) == true)
            return true;
        
        board[currow][curcol] = word[curidx];
        
        return false;
        
    }
};