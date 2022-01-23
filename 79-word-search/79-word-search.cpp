class Solution {
public:
    bool dfs(vector<vector<char>> &board, string word, int row, int col, int curr)
    {
        if(curr >= word.size())
            return true;
        
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '.')
            return false;
        
        if(board[row][col] != word[curr])
            return false;
        
        char temp = board[row][col];
        board[row][col] = '.';
        
        if(dfs(board, word, row + 1, col, curr + 1) || dfs(board, word, row - 1, col, curr+1) || dfs(board, word, row, col + 1,  curr + 1) || dfs(board, word, row, col - 1, curr + 1))
            return true;
        
        board[row][col] = temp;
        return false;
        
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0; i< board.size(); i++)
        {
            for(int j =0; j < board[0].size(); j++)
            {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }

};